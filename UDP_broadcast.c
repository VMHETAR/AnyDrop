#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#define PORT 5000
#define MAXLINE 1000

int main(){
    WSADATA wsdata;
    char buffer[100];
    int listenfd, len;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));

    // Create a UDP socket
    listenfd = socket(AF_INET,SOCK_DGRAM,0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
}