#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    int reuse = 1;
    setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    printf("Enter existing filename: ");
    fgets(buffer, 100, stdin);
    send(clientSocket, buffer, strlen(buffer), 0);

    printf("Enter new filename to save: ");
    fgets(buffer, 100, stdin);

    FILE* file = fopen(buffer, "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (1) {
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) break;
        fwrite(buffer, 1, bytesRead, file);
    }

    fclose(file);
    printf("File received successfully.\n");
    return 0;
}
