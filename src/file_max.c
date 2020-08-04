#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


#define MAX_FILESIZE 1000000


int main(int argc, char ** argv)
{
    unsigned long i,length;
    int fd;
    char namebuf[100];
    char prefix[] = "/tmp/p";
    strcpy(namebuf, prefix);
    length = strlen(namebuf);

    /* start of test */
    for (i = 0; i < MAX_FILESIZE; ++i) {
        sprintf(namebuf+length, "%d", i);
        fd = open(namebuf ,O_CREAT | O_RDWR, 0777);
    }
    sleep(300);
    for (i = 0; i < MAX_FILESIZE; ++i) {
        sprintf(namebuf+length, "%d", i);
        remove(namebuf);
    }
    return 0;
}
