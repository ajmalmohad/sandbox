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
    time_t tick;

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    int reuse = 1;
    setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    while(1){
        printf("Enter a Word: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(clientSocket, buffer, sizeof(buffer), 0);

        int i = 2;
        while(i){
            recv(clientSocket, buffer, 1024, 0);
            if(i==2) printf("Meaning: %s \n", buffer);
            if(i==1) printf("Antonym: %s \n", buffer);
            i--;
        }
    }
    
    return 0;
}