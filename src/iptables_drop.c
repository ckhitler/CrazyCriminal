#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char* argv[])
{
    pid_t status;
    char namebuf[500];
    sprintf(namebuf,"iptables -P INPUT DROP");
    status = system(namebuf);
    if ( -1 == status){
        perror("system error!");
        exit(1);
    }else{
        if (WIFEXITED(status)){
            if (0 == WEXITSTATUS(status)){
                printf("[Success]iptables -P INPUT DROP\n");
            }else{
                printf("[Failed]iptables -P INPUT DROP: exit code: %d\n",\
                        WEXITSTATUS(status));
                exit(1);
            }
        }else{
            printf("exit status = [%d]\n", WEXITSTATUS(status));
            exit(1);
        }
    }
    sleep(60);

    sprintf(namebuf,"iptables -P INPUT ACCEPT");
    status = system(namebuf);
    if ( -1 == status){
        perror("system error!");
        exit(1);
    }else{
        if (WIFEXITED(status)){
            if (0 == WEXITSTATUS(status)){
                printf("[Success]iptables -P INPUT ACCEPT\n");
            }else{
                printf("[Failed]iptables -P INPUT ACCEPT:exit code: %d\n",\
                        WEXITSTATUS(status));
                exit(1);
            }
        }else{
            printf("exit status = [%d]\n", WEXITSTATUS(status));
            exit(1);
        }
    }
}
