#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressLength;
    char buffer[1024];

    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(7891);

    bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    while (1) {
        // Receive Message from client
        memset(buffer, 0, 1024);
        clientAddressLength = sizeof(clientAddress);
        recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddress, &clientAddressLength);
        printf("Client: %s", buffer);

        // Send Message to the client
        printf("Server: ");
        fgets(buffer, 1024, stdin);
        sendto(serverSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&clientAddress, clientAddressLength);
    }

    close(serverSocket);
    return 0;
}