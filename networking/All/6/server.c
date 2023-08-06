#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    char dictionary[3][3][100] = {
        {"Big", "Large Size", "Small"},
        {"Small", "Tiny Size", "Big"},
        {"Empty", "Nothing", "Full"},
    };

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
    while(1){
        int newSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &addr_size);
        int pid;
        if((pid=fork())==0){
            char buffer[1024];
            while(recv(newSocket, buffer, sizeof buffer, 0)){
                buffer[strcspn(buffer, "\n")] = '\0';
                int found = 0;
                for(int i=0; i<3; i++){
                    if(strcmp(buffer, dictionary[i][0])==0){
                        found = 1;
                        strcpy(buffer, "Meaning: ");
                        strcat(buffer, dictionary[i][1]);
                        strcat(buffer, "\nAntonym: ");
                        strcat(buffer, dictionary[i][2]);
                        break;
                    }
                }
                if(!found) strcpy(buffer, "Not Found");
                send(newSocket, buffer, sizeof buffer, 0);
            }
        }
    }
}