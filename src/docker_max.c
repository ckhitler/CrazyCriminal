#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


#define MAX_CONTAINERS 1000


int main(int argc, char ** argv)
{
    pid_t status;
    unsigned long i;
    char namebuf[500];
    for (i = 0; i < MAX_CONTAINERS; ++i) {
       sprintf(namebuf,"curl  -d '{\"image\":\"mirrorgooglecontainers/pause-amd64:3.1\"}' \
                        -X POST -H 'Content-Type: application/json' \
                        http://127.0.0.1:900/containers/create?name=demo_%d",i);
       status = system(namebuf);
       if ( -1 == status){
           perror("system error!");
           exit(1);
       }else{
            if (WIFEXITED(status)){
                if (0 == WEXITSTATUS(status)){
                    printf("[Success]create containers %d\n",i);
                }else{
                    printf("[Failed]create containers %d:exit code: %d\n",\
                        i,WEXITSTATUS(status));
                    exit(1);
                }
            }else{
                printf("exit status = [%d]\n", WEXITSTATUS(status));
                exit(1);
            }
       }
       sprintf(namebuf,"curl   -X POST -H 'Content-Type: application/json' \
                         http://127.0.0.1:900/containers/demo_%d/start?name=demo_%d", i, i);
       status = system(namebuf);
       if ( -1 == status){
           perror("system error!");
           exit(1);
       }else{
            if (WIFEXITED(status)){
                if (0 == WEXITSTATUS(status)){
                    printf("[Success]start containers %d\n",i);
                }else{
                    printf("[Failed]start containers %d:exit code: %d\n",\
                        i,WEXITSTATUS(status));
                    exit(1);
                }
            }else{
                printf("exit status = [%d]\n", WEXITSTATUS(status));
                exit(1);
            }
       }
    }
    sleep(300);

    for (i = 0; i < MAX_CONTAINERS; ++i) {
        sprintf(namebuf,"curl   -X DELETE -H 'Content-Type: application/json' \
                         http://127.0.0.1:900/containers/demo_%d?force=1", i);
        status = system(namebuf);
        if ( -1 == status){
           perror("system error!");
           exit(1);
        }else{
            if (WIFEXITED(status)){
                if (0 == WEXITSTATUS(status)){
                    printf("[Success]delete containers %d\n",i);
                }else{
                    printf("[Failed]delete containers %d:exit code: %d\n",\
                        i,WEXITSTATUS(status));
                    exit(1);
                }
            }else{
                printf("exit status = [%d]\n", WEXITSTATUS(status));
                exit(1);
            }
        }
    }

    return 0;
}
