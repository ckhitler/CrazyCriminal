#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROC 9999


int main(void)
{
    unsigned long i;
    pid_t pids[MAX_PROC];

    /* start of test */
    for (i = 0; i < MAX_PROC; ++i) {
        if (!(pids[i] = fork())) {
            sleep(60);
            exit(0);
        }
        if (pids[i] < 0) {
            perror("fork");
            exit(1);
        }
    }
    for (i = 0; i < MAX_PROC; ++i) {
        waitpid(pids[i], NULL, 0);
    }
    return 0;

}
