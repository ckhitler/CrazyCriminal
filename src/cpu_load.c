#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PRIME 1000000

void do_primes()
{
    unsigned long i, num, primes = 0;
    for (num = 1; num <= MAX_PRIME; ++num) {
        for (i = 2; (i <= num) && (num % i != 0); ++i);
        if (i == num)
            ++primes;
    }
    printf("Calculated %d primes.\n", primes);
}

int main(int argc, char * argv[])
{
    unsigned int ngx_ncpu = 0;
    ngx_ncpu = sysconf(_SC_NPROCESSORS_ONLN) * 2;
    unsigned long i;
    pid_t pids[ngx_ncpu];

    for (i = 0; i < ngx_ncpu; ++i) {
        if (!(pids[i] = fork())) {
            do_primes();
            exit(0);
        }
        if (pids[i] < 0) {
            perror("Fork");
            exit(1);
        }
    }
    for (i = 0; i < ngx_ncpu; ++i) {
        waitpid(pids[i], NULL, 0);
    }
    return 0;
}
