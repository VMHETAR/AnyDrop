#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int check(int exp, const char *msg);

int main(int argc, char **argv){
    if(argc!= 2){
        printf("Usage: %s <port>\n",argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);
    int udp_rsocket;
    struct sockaddr_in peer_addr;
    struct sockaddr_in my_addr = {.sin_family=AF_INET, .sin_addr=INADDR_ANY, .sin_port=htons(port)};
    

}