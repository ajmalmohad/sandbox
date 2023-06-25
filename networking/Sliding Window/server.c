#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define WINDOW_SIZE 4

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
    bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if (listen(welcomeSocket, 5) == 0)
        printf("Listening\n");
    else
        printf("Error");

    addr_size = sizeof serverStorage;
    newSocket = accept(welcomeSocket, (struct sockaddr *)&serverAddr, &addr_size);

    char message[1024] = {'\0'};
    char inputs[50];

    printf("Enter the text to send: ");
    fgets(inputs, sizeof(inputs), stdin);
    inputs[strcspn(inputs, "\n")] = '\0';

    int length = strlen(inputs);
    int start = 0;
    int end = 3;

    while (start < length) {
        memset(message, '\0', sizeof(message));
        strncpy(message, inputs + start, 4);

        char indexStr[1024];
        memset(indexStr, '\0', sizeof(indexStr));
        int index = start;
        while (index <= end) {
            char numStr[5];
            sprintf(numStr, "%d", index);
            strcat(indexStr, numStr);
            index++;
        }
        strcat(message, indexStr);

        printf("Frame Transmitted: %s\n", message);
        send(newSocket, message, sizeof(message), 0);
        start += 4;
        end += 4;

        if (end >= length) end = length - 1;

        int retransmitIndex;
        if (recv(newSocket, &retransmitIndex, sizeof(retransmitIndex), 0)) {
            if(retransmitIndex > -1){
                printf("Retransmitting from index %d\n", retransmitIndex);
                start = retransmitIndex;
                end = start + 3;
            }
        }
    }

    printf("Transmission Successful\n");
    return 0;
}
