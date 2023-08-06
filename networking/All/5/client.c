#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9871);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);
    char buffer[1024];
    socklen_t addr_size = sizeof serverAddress;

    while(1){
        printf("Enter the message to send: ");
        fgets(buffer, sizeof buffer, stdin);
        sendto(clientSocket, buffer, sizeof buffer, 0, (struct sockaddr *) &serverAddress, addr_size);
        
        recvfrom(clientSocket, buffer, sizeof buffer, 0, (struct sockaddr *) &serverAddress, &addr_size);
        printf("Server: %s", buffer);
    }
}