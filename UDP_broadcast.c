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

    
}