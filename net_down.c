#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char* argv[])
{
    pid_t status;
    char namebuf[500];
    if (argc != 2){
        printf("need to specify the nic.\nexample: net_down eth1\n");
        exit(1);
    }
    sprintf(namebuf,"ip link set %s down",argv[1]);
    status = system(namebuf);
    if ( -1 == status){
        perror("system error!");
        exit(1);
    }else{
        if (WIFEXITED(status)){
            if (0 == WEXITSTATUS(status)){
                printf("[Success]ip link set %s down\n",argv[1]);
            }else{
                printf("[Failed]ip link set %s down: exit code: %d\n",\
                        argv[1],WEXITSTATUS(status));
                exit(1);
            }
        }else{
            printf("exit status = [%d]\n", WEXITSTATUS(status));
            exit(1);
        }
    }
    sleep(60);

    sprintf(namebuf,"ip link set %s up",argv[1]);
    status = system(namebuf);
    if ( -1 == status){
        perror("system error!");
        exit(1);
    }else{
        if (WIFEXITED(status)){
            if (0 == WEXITSTATUS(status)){
                printf("[Success]ip link set %s up\n",argv[1]);
            }else{
                printf("[Failed]ip link set %s up:exit code: %d\n",\
                        argv[1],WEXITSTATUS(status));
                exit(1);
            }
        }else{
            printf("exit status = [%d]\n", WEXITSTATUS(status));
            exit(1);
        }
    }
}
