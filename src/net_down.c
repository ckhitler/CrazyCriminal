#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <errno.h>
#include  <sys/ioctl.h>
#include  <sys/types.h>
#include  <sys/socket.h>
#include  <linux/if.h>

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
#include  <linux/sockios.h>
#include  <linux/ethtool.h>
int set_netlink_status(const char *if_name, short flag);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "usage: %s <ethname>\n", argv[0]);
        return -1;
    }

    set_netlink_status(argv[1],1 & ~IFF_UP);
    sleep (60);
    set_netlink_status(argv[1],1 | IFF_UP);
    return 0;
}

int set_netlink_status(const char *if_name, short flags)
{
    int skfd;
    struct ifreq ifr;
    struct ethtool_value edata;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, if_name, sizeof(ifr.ifr_name) - 1);
    ifr.ifr_flags = flags;
    if (( skfd = socket( AF_INET, SOCK_DGRAM, 0 )) == 0)
        return -1;
    if(ioctl( skfd, SIOCSIFFLAGS, &ifr ) == -1)
    {
        close(skfd);
        return -1;
    }
    close(skfd);
    return edata.data;
}

