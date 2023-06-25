#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
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

    while(1){
        char inputs[50];
        char message[1024] = {'\0'};

        printf("\nEnter From Address: ");
        scanf("%s", inputs);
        strcat(message, "Mail From: ");
        strcat(message, inputs);
        strcat(message, "\n");

        printf("Enter To Address: ");
        scanf("%s", inputs);
        strcat(message, "Mail To: ");
        strcat(message, inputs);
        strcat(message, "\n");

        printf("Enter Mail Body: ");
        getchar();
        fgets(inputs, sizeof(inputs), stdin);
        strcat(message, "Mail Body: ");
        strcat(message, inputs);
        strcat(message, "\n");

        send(clientSocket, message, sizeof(message), 0);
    }
    
    return 0;
}