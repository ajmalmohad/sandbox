#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[1024];

    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(7891);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1) {
        // Send Message to Server
        printf("Client: ");
        fgets(buffer, 1024, stdin);
        sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

        // Receive message from Server
        memset(buffer, 0, 1024);
        socklen_t serverAddressLength = sizeof(serverAddress);
        recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddress, &serverAddressLength);
        printf("Server: %s", buffer);
    }

    close(clientSocket);
    return 0;
}
