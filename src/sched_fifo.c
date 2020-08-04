#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_PRIME 1000000

static void *fn(void *p)
{
    unsigned long i, num, primes = 0;
    for (num = 1; num <= MAX_PRIME; ++num) {
        for (i = 2; (i <= num) && (num % i != 0); ++i);
        if (i == num)
            ++primes;
    }
    return NULL;
}

int main(void)
{
    struct sched_param sp;
    pthread_t t;

    if (pthread_create(&t, NULL, fn, NULL) != 0){
        perror("Create pthread failed");
        exit(1);
    }

    memset(&sp, 0, sizeof(sp));
    sp.__sched_priority = 80;
    if (pthread_setschedparam(t, SCHED_FIFO, &sp) != 0){
        perror("Create pthread failed");
        exit(1);
    }

    sleep(60);
    exit(0);
}
