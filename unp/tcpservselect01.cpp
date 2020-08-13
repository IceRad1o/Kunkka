#include "unp.h"

int main(int argc, char**agrv)
{
    int listenfd, connfd, sockfd;
    int i, maxi, maxfd;
    ssize_t n;
    int nready, client[FD_SETSIZE];
    char buf[MAXLINE];
    socklen_t clilen;
    fd_set rset, allset;
    struct sockaddr_in servaddr, cliaddr;

    bzero(&servaddr, sizeof(servaddr));
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    maxfd = listenfd;
    maxi = -1;
    for(int i=0; i<FD_SETSIZE; i++){
        client[i] = -1;
    }
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    for(; ;){
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);

        if(FD_ISSET(listenfd, &rset)){ // new client connection
            clilen = sizeof(cliaddr);
            connfd = Accept(listenfd, (SA*)&cliaddr, &clilen);
            for(i=0; i<FD_SETSIZE; i++){
                if(client[i]<0){
                    client[i] = connfd; //save fd
                    break;
                }
            }
            if(i==FD_SETSIZE)
                err_quit("too many clients");

            FD_SET(connfd, &allset);
            if(connfd > maxfd)
                maxfd = connfd;
            if(i> maxi)
                maxi = i;
            if(--nready <=0)
                continue;
        }

        for(i=0; i<=maxi; i++){ //check all clients
            if( (sockfd = client[i])<0 )
                continue;
            if( FD_ISSET(sockfd, &allset)){
                if( (n=Read(sockfd, buf, MAXLINE))==0 ){
                    /* connection close by client*/
                    Close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                } else{
                    Writen(sockfd, buf, n);
                }
                if(--nready <= 0)
                    break;
            }
        }
    }
}