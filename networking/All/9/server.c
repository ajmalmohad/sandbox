#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

int main(){
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9871);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);

    int reuse = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse);
    bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof serverAddress);
    
    if(listen(serverSocket, 5)==0) printf("Listening...\n");

    struct sockaddr_storage clientAddress;
    socklen_t addr_size = sizeof clientAddress;
    int newSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &addr_size);
    
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
        char sizes[10];
        for(int j=i; j<i+frame_size; j++){
            sprintf(sizes, " %d", j+1);
            strcat(frame, sizes);
        }
        i+=frame_size;
        send(newSocket, frame, sizeof frame, 0);

        int error;
        recv(newSocket, &error, sizeof error, 0);
        if(error == 0){
            printf("Frame Successfully Sent!\n");
        }else{
            printf("Retransmitting from Index: %d\n", error-1);
            i = error - 1;
        }
    }

}