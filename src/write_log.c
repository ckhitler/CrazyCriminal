#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>


#define MAX_FILESIZE 1000000000
#define MAX_PROC 10

int do_writefile()
{
    int i,num = 0;
    char namebuf[100];
    char prefix[] = "/tmp/p";
    int length, pid, fd;
    int n = 8;

    pid = getpid();
    strcpy(namebuf, prefix);
    length = strlen(namebuf);
    sprintf(namebuf+length, "%d", pid);

    char *buff = "testing"; // declaring buffer

    // creating a new file using open.
    fd=open(namebuf ,O_CREAT | O_RDWR, 0777);

    //writting input data to file (fd)
    for (i=0;i<=MAX_FILESIZE;i++){
      write(fd, buff, n);
    }

    //closing the file
    close(fd);

    //delete the file
    remove(namebuf);

    return 0;

}

int main(int argc, char * argv[])
{
    unsigned long i;
    pid_t pids[MAX_PROC];

    /* start of test */
    for (i = 0; i < MAX_PROC; ++i) {
        if (!(pids[i] = fork())) {
            do_writefile();
            exit(0);
        }
        if (pids[i] < 0) {
            perror("Fork");
            exit(1);
        }
    }
    for (i = 0; i < MAX_PROC; ++i) {
        waitpid(pids[i], NULL, 0);
    }
    return 0;
}
