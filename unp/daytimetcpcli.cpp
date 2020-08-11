//
// Created by Jialei Wang on 2020/8/11.
//
#include "unp.h"

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE+1];

    if(argc!=2){
        printf("usage: a <IPaddress>");
    }

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(9090);	/* daytime server */
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        printf("inet_pton error for %s", argv[1]);

    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        printf("connect error");

    while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;	/* null terminate */
        if (fputs(recvline, stdout) == EOF)
            printf("fputs error");
    }
    if (n < 0)
        printf("read error");

    exit(0);

}