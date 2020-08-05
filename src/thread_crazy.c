#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


static void *fn(void *p)
{
    while (1) sleep(60);
    return NULL;
}

int main(void)
{
    struct sched_param sp;
    pthread_t t;
    int fd;
    char s[32];

    unsigned long i;
    fd = open("/proc/sys/kernel/threads-max",O_RDONLY);
    if (fd == -1){
        perror("open file error");
        exit(1);
    }
    read(fd,s,sizeof(s));
    int max_threads=atoi(s);
    printf("%d",max_threads);
    close(fd);

    for (i = 0; i < max_threads-1000; ++i) {
        if (pthread_create(&t, NULL, fn, NULL) != 0){
            perror("fail create pthread");
            exit(1);
	}
    }

    sleep(60);
    exit(0);
}
