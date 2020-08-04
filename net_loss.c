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
        printf("need to specify the nic.\nexample: net_loss eth1\n");
        exit(1);
    }
    sprintf(namebuf,"tc qdisc add dev %s root netem loss 20%",argv[1]);
    status = system(namebuf);
    if ( -1 == status){
        perror("system error!");
        exit(1);
    }else{
        if (WIFEXITED(status)){
            if (0 == WEXITSTATUS(status)){
                printf("[Success]tc qdisc add dev %s root netem loss 20%\n",argv[1]);
            }else{
                printf("[Failed]tc qdisc add dev %s root netem loss 20%:exit code: %d\n",\
                        argv[1],WEXITSTATUS(status));
                exit(1);
            }
        }else{
            printf("exit status = [%d]\n", WEXITSTATUS(status));
            exit(1);
        }
    }
    sleep(60);

    sprintf(namebuf,"tc qdisc del dev %s root netem loss 20%",argv[1]);
    status = system(namebuf);
    if ( -1 == status){
        perror("system error!");
        exit(1);
    }else{
        if (WIFEXITED(status)){
            if (0 == WEXITSTATUS(status)){
                printf("[Success]tc qdisc del dev %s root netem loss 20%\n",argv[1]);
            }else{
                printf("[Failed]tc qdisc del dev %s root netem loss 20%:exit code: %d\n",\
                        argv[1],WEXITSTATUS(status));
                exit(1);
            }
        }else{
            printf("exit status = [%d]\n", WEXITSTATUS(status));
            exit(1);
        }
    }
}
