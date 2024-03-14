#ifndef __TIME_H__
#define __TIME_H__
#include <internal/types.h>
#include <unistd.h>

struct timespec {
    int64_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);
#endif
