#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


#define SIG_MAX 30000

volatile int done = 0;

void handler (int sig)
{
    const char *str = "handled...\n";
    write (1, str, strlen(str));
    done = 1;
}

void child(void)
{
    int i;
    for (i = 0; i < SIG_MAX; i++){
        kill(getppid(), SIGRTMIN);
    }
    exit (0);
}

int main (int argc, char *argv[])
{
    signal (SIGRTMIN, handler);
    sigset_t newset, oldset;
    
    sigfillset(&newset);
    sigprocmask(SIG_BLOCK, &newset, &oldset);
    
    pid_t pid = fork();
    if (pid == 0)
    child();
    
    
    int r = sleep(60);
    
    
    sigprocmask(SIG_SETMASK, &oldset, NULL);
    
    while (!done){
    };
    
    exit(0);
}

