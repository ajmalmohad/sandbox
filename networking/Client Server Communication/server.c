#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    int reuse = 1;
    setsockopt(welcomeSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if(listen(welcomeSocket, 5) == 0){
        printf("Listening\n");
    }else{
        printf("Error\n");
    }

    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);
    strcpy(buffer, "Hello World");
    send(newSocket, buffer, 13, 0);
    
    return 0;
}