//
// Created by jialeiwang on 8/14/20.
//
#include "Define.h"

int setnonblocking(int fd)
{
    int old_flags = fcntl(fd, F_GETFL);
    int new_flags = old_flags|O_NONBLOCK;
    fcntl(fd, F_SETFL, new_flags);
    return old_flags;
}
