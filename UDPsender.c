#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORT 5000
#define MAXLINE 1000

int main(int argc, char *argv[]) {

    if(argc != 4){
        printf("Usage: %s <peer_ip> <peer_port> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    const char *peer_ip = argv[1];
    int peer_port = atoi(argv[2]);
    const char *message = argv[3];

    struct sockaddr_in peer_addr;
    peer_addr.sin_family = AF_INET;
    peer_addr.sin_port = htons(peer_port);

    if (inet_pton(AF_INET, peer_ip, &(peer_addr.sin_addr)) <= 0){
        perror("Invalid IP address");
        return EXIT_FAILURE;
    }

    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_socket < 0){
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    if(sendto(udp_socket, message, strlen(message)+1, 0,
        (struct sockaddr*)&peer_addr, sizeof(peer_addr)) < 0){
        perror("Failed to send message");
        closesocket(udp_socket);
        return EXIT_FAILURE;
    }

    closesocket(udp_socket);
    WSACleanup();
}