#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    void *ptr;
    int n = 0;
    while (1){
        ptr = malloc(0x100000);
        if (ptr == NULL)
            break;
        memset(ptr, 1, 0x100000);
        sleep(5);
    }
}
