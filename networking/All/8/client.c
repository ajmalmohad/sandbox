#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9871);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);

    int reuse = 1;
    setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse);
    connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof serverAddress);

    char buffer[1024];
    printf("Enter the file you want: ");
    fgets(buffer, sizeof buffer, stdin);
    send(clientSocket, buffer, sizeof buffer, 0);

    printf("Enter the file to output: ");
    fgets(buffer, sizeof buffer, stdin);
    FILE* file = fopen(buffer, "wb");

    int bytesRead;
    while(bytesRead = recv(clientSocket, buffer, sizeof buffer, 0)){
        if(strcmp(buffer, "NF") == 0){
            printf("File not Found\n");
            break;
        }
        fwrite(buffer, 1, bytesRead, file);
    }
    
}