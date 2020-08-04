#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#define MAX_PROC 19999

static void *fn(void *p)
{
    while (1) sleep(60);
    return NULL;
}

int main(void)
{
    struct sched_param sp;
    pthread_t t;

    unsigned long i;

    /* start of test */
    for (i = 0; i < MAX_PROC; ++i) {
        if (pthread_create(&t, NULL, fn, NULL) != 0){
            perror("fail create pthread");
            exit(1);
	}
    }

    sleep(600);
    exit(0);
}
