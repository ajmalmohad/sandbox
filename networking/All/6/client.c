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
    while(1){
        printf("Enter a word: ");
        fgets(buffer, sizeof buffer, stdin);
        send(clientSocket, buffer, sizeof buffer, 0);
        recv(clientSocket, buffer, sizeof buffer, 0);
        printf("%s\n", buffer);
    }
}