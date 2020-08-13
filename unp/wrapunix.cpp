#include	"unp.h"

void *
Calloc(size_t n, size_t size)
{
    void	*ptr;

    if ( (ptr = calloc(n, size)) == NULL)
        err_sys("calloc error");
    return(ptr);
}

void
Close(int fd)
{
    if (close(fd) == -1)
        err_sys("close error");
}

void
Dup2(int fd1, int fd2)
{
    if (dup2(fd1, fd2) == -1)
        err_sys("dup2 error");
}

int
Fcntl(int fd, int cmd, int arg)
{
    int	n;

    if ( (n = fcntl(fd, cmd, arg)) == -1)
        err_sys("fcntl error");
    return(n);
}


int
Ioctl(int fd, int request, void *arg)
{
    int		n;

    if ( (n = ioctl(fd, request, arg)) == -1)
        err_sys("ioctl error");
    return(n);	/* streamio of I_LIST returns value */
}

pid_t
Fork(void)
{
    pid_t	pid;

    if ( (pid = fork()) == -1)
        err_sys("fork error");
    return(pid);
}

void *
Malloc(size_t size)
{
    void	*ptr;

    if ( (ptr = malloc(size)) == NULL)
        err_sys("malloc error");
    return(ptr);
}


#include	<sys/mman.h>

void *
Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
    void	*ptr;

    if ( (ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1))
        err_sys("mmap error");
    return(ptr);
}

int
Open(const char *pathname, int oflag, mode_t mode)
{
    int		fd;

    if ( (fd = open(pathname, oflag, mode)) == -1)
        err_sys("open error for %s", pathname);
    return(fd);
}

void
Pipe(int *fds)
{
    if (pipe(fds) < 0)
        err_sys("pipe error");
}

ssize_t
Read(int fd, void *ptr, size_t nbytes)
{
    ssize_t		n;

    if ( (n = read(fd, ptr, nbytes)) == -1)
        err_sys("read error");
    return(n);
}

char *
Strdup(const char *str)
{
    char	*ptr;

    if ( (ptr = strdup(str)) == NULL)
        err_sys("strdup error");
    return(ptr);
}

long
Sysconf(int name)
{
    long	val;

    errno = 0;		/* in case sysconf() does not change this */
    if ( (val = sysconf(name)) == -1)
        err_sys("sysconf error");
    return(val);
}

#ifdef	HAVE_SYS_SYSCTL_H
void
Sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp,
	   void *newp, size_t newlen)
{
	if (sysctl(name, namelen, oldp, oldlenp, newp, newlen) == -1)
		err_sys("sysctl error");
}
#endif

void
Unlink(const char *pathname)
{
    if (unlink(pathname) == -1)
        err_sys("unlink error for %s", pathname);
}

pid_t
Wait(int *iptr)
{
    pid_t	pid;

    if ( (pid = wait(iptr)) == -1)
        err_sys("wait error");
    return(pid);
}

pid_t
Waitpid(pid_t pid, int *iptr, int options)
{
    pid_t	retpid;

    if ( (retpid = waitpid(pid, iptr, options)) == -1)
        err_sys("waitpid error");
    return(retpid);
}

void
Write(int fd, void *ptr, size_t nbytes)
{
    if (write(fd, ptr, nbytes) != nbytes)
        err_sys("write error");
}
