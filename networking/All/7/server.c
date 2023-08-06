#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9871);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);

    int reuse = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse);
    bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof serverAddress);

    if(listen(serverSocket, 5)==0) printf("Listening...\n");

    struct sockaddr_storage clientAddress;
    socklen_t addr_size = sizeof clientAddress;  
    int newSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &addr_size);
    char buffer[1024];
    while(recv(newSocket, buffer, sizeof buffer, 0)){
        printf("%s\n", buffer);
    }
}