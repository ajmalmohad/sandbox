#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

int main(){
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9871);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);

    int reuse = 1;
    setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse);
    connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof serverAddress);

    char buffer[1024];
    printf("Enter the text you want to send: ");
    fgets(buffer, sizeof buffer, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    int i=0;
    while(i < strlen(buffer)){
        char frame[20];
        memset(frame, '\0', sizeof frame);
        strncpy(frame, buffer+i, 4);
        int frame_size = strlen(frame);
        i+=frame_size;
        send(clientSocket, frame, sizeof frame, 0);

        int ack;
        recv(clientSocket, &ack, sizeof ack, 0);
        if(ack == 0){
            printf("Acknowledgement Not Recieved! Retransmitting...\n");
            i -= frame_size;
        }else{
            printf("Acknowledgment Recieved!");
        }
    }

}