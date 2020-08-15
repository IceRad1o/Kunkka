#include "unp.h"
/* JUST mini-muduo the select function, the program is not right for echo. the question comes at fgets */
void str_cli_select01(FILE *fp, int sockfd)
{
    int maxfdp1;
    fd_set rset;
    char sendline[MAXLINE], recvline[MAXLINE];
    FD_ZERO(&rset);
    for(; ;){
        FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdp1 = max(fileno(fp), sockfd)+1;
        select(maxfdp1, &rset, NULL, NULL, NULL);

        if(FD_ISSET(sockfd, &rset)) { /* socket is readable */
            if(Readline(sockfd, recvline, MAXLINE) == 0){
                err_quit("str_cli: server terminated prematureley");
            }
            fputs(recvline, stdout);
        }

        if(FD_ISSET(fileno(fp), &rset)){ /* input is readable*/
            if(fgets(sendline, MAXLINE, fp)== NULL){
                return;
            }
            Writen(sockfd, sendline, strlen(sendline));
        }
    }
}

/* str_cli的问题在于，如果socket发生了事件， 客户还阻塞在fgets这里，这个版本阻塞在select，等待stdin或者是socket可读*/
