#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    int reuse = 1;
    setsockopt(welcomeSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    bind(welcomeSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if (listen(welcomeSocket, 5) == 0) printf("Listening\n");
    else printf("Error\n");

    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr*)&serverAddr, &addr_size);

    recv(newSocket, buffer,100, 0);
    buffer[strcspn(buffer, "\n")] = '\0';
    printf("Sending %s....\n", buffer);

    FILE* file = fopen(buffer, "rb");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while (1) {
        ssize_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
        if (bytesRead <= 0) break;
        send(newSocket, buffer, bytesRead, 0);
    }

    fclose(file);
    printf("File sent successfully.\n");

    return 0;
}