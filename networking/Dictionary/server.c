#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    char dict[3][3][100] = {
        {"Cat", "a small domesticated carnivorous mammal", "dog"},
        {"Happy", "feeling or showing pleasure or joy", "sad"},
        {"Big", "of considerable size or extent", "small"}
    };

    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    int reuse = 1;
    setsockopt(welcomeSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if(listen(welcomeSocket, 5) == 0) printf("Listening\n");
    else printf("Error");

    addr_size = sizeof serverStorage;

    newSocket = accept(welcomeSocket, (struct sockaddr *)&serverAddr, &addr_size);
    while(recv(newSocket, buffer, sizeof(buffer), 0)){
        buffer[strcspn(buffer, "\n")] = '\0';
        int found = 0;
        for(int i=0; i<3; i++){
            if(strcmp(buffer, dict[i][0]) == 0){
                printf("Word Found\n");
                found = 1;
                strcpy(buffer, dict[i][1]);
                send(newSocket, buffer, sizeof(buffer), 0);
                strcpy(buffer, dict[i][2]);
                send(newSocket, buffer, sizeof(buffer), 0);
                break;
            }
        }

        if(!found){
            strcpy(buffer, "Not found");
            send(newSocket, buffer, sizeof(buffer), 0);
            send(newSocket, buffer, sizeof(buffer), 0);
        }
        
        found = 0;
    }

    return 0;
}