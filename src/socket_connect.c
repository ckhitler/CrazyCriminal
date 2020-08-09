#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PROC 10000

static void *fn(void *p)
{
        int fd;
        struct sockaddr_in sa;
        int port = 900;
        fd = socket(AF_INET,SOCK_STREAM, 0);
        if (fd < 0){
                perror("socket fail");
                exit(1);
        }
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = inet_addr("127.0.0.1");
        sa.sin_port = htons(port);

        if (connect(fd, (struct sockaddr*)&sa, sizeof(sa)) < 0){
                perror("connect fail");
        }else{
                sleep(60);
        }
        close(fd);
}


int main(int argc, char * argv[])
{
        pthread_t t;
	long int i;

        for (i = 0; i < MAX_PROC; ++i) {
            if (pthread_create(&t, NULL, fn, NULL) != 0){
                perror("fail create pthread");
                exit(1);
            }
        }
        sleep(60);
	exit (0);

}
