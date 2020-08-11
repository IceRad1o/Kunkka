//
// Created by Jialei Wang on 2020/8/11.
//

#ifndef RANET_UNP_H
#define RANET_UNP_H

#include <arpa/inet.h> // htonl,htons
#include <cstdio> //snprintf
#include <memory.h> //
#include <netinet/in.h> // sockaddr_in
#include <stdlib.h>
#include <strings.h> //bzeros
#include <sys/socket.h>
#include <unistd.h> // read,write,close
#define SA struct sockaddr

const int MAXLINE = 4096;
const int LISTENQ = 1024;


/* wrap functions */
int Accept(int, SA*, socklen_t);
void Bind(int, const SA*, socklen_t);
void Connect(int, const SA*, socklen_t);

int Socket(int, int, int);
#endif //RANET_UNP_H
