#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    int reuse = 1;
    setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    while (recv(clientSocket, buffer, sizeof(buffer), 0)) {
        printf("Received: %s\n", buffer);

        int choice;
        printf("1. Is this correct? (1-YES, 0-NO): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Transmission Successful\n");
            int index = -1;
            send(clientSocket, &index, sizeof(index), 0);
        } else {
            int index;
            printf("Enter the index to retransmit from: ");
            scanf("%d", &index);
            send(clientSocket, &index, sizeof(index), 0);
        }

        memset(buffer, '\0', sizeof(buffer));
    }

    return 0;
}
