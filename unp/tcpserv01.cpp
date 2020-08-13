#include "unp.h"

int main()
{
    int listenfd, connfd;
    struct sockaddr_in cliaddr, servaddr;
    pid_t childpid;
    socklen_t clilen;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    Bind(listenfd,(SA*)&servaddr,sizeof(servaddr));

    Listen(listenfd,LISTENQ);

    for(; ;){
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA*)&cliaddr, &clilen);
        if( (childpid = fork()) == 0){ // child process
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd); // parent cloase connected socket
    }
}

