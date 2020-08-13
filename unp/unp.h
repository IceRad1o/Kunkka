#ifndef RANET_UNP_H
#define RANET_UNP_H

#include <arpa/inet.h> // htonl,htons
#include <cstdio> //snprintf
#include <errno.h>
#include <fcntl.h>
#include <memory.h> //
#include <netinet/in.h> // sockaddr_in
#include <stdlib.h>
#include <strings.h> //bzeros
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h> // read,write,close
#define SA struct sockaddr

const int MAXLINE = 4096;
const int LISTENQ = 1024;
const int SERV_PORT = 9877;

template <typename T>
inline int max(const T&a, const T&b){
    return (a>b?a:b);
}

/* wrap functions */
int Socket(int, int, int);
void Bind(int, const SA*, socklen_t);
void Connect(int, const SA*, socklen_t);
void Listen(int, int);
int Accept(int, SA*, socklen_t*);

/* error functions */
void	 err_dump(const char *, ...);
void	 err_msg(const char *, ...);
void	 err_quit(const char *, ...);
void	 err_ret(const char *, ...);
void	 err_sys(const char *, ...);

/* unix wrap functions */
void	*Calloc(size_t, size_t);
void	 Close(int);
void	 Dup2(int, int);
int		 Fcntl(int, int, int);
void	 Gettimeofday(struct timeval *, void *);
int		 Ioctl(int, int, void *);
pid_t	 Fork(void);
void	*Malloc(size_t);
int	 Mkstemp(char *);
void	*Mmap(void *, size_t, int, int, int, off_t);
int		 Open(const char *, int, mode_t);
void	 Pipe(int *fds);
ssize_t	 Read(int, void *, size_t);
void	 Sigaddset(sigset_t *, int);
void	 Sigdelset(sigset_t *, int);
void	 Sigemptyset(sigset_t *);
void	 Sigfillset(sigset_t *);
int		 Sigismember(const sigset_t *, int);
void	 Sigpending(sigset_t *);
void	 Sigprocmask(int, const sigset_t *, sigset_t *);
char	*Strdup(const char *);
long	 Sysconf(int);
void	 Sysctl(int *, u_int, void *, size_t *, void *, size_t);
void	 Unlink(const char *);
pid_t	 Wait(int *);
pid_t	 Waitpid(pid_t, int *, int);
void	 Write(int, void *, size_t);

/* robust io */
// 因为在网络编程中， read和write输入或者输出打byte可能比请求的少
ssize_t	 readline(int, void *, size_t);
ssize_t	 readn(int, void *, size_t);
ssize_t	 writen(int, const void *, size_t);

ssize_t	 Readline(int, void *, size_t);
ssize_t	 Readn(int, void *, size_t);
void	 Writen(int, void *, size_t);

/* prototypes for library functions */
void str_echo(int);
void str_cli(FILE *, int);
void str_cli_select01(FILE *, int);

#endif //RANET_UNP_H
