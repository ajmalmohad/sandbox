#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
  addr_size = sizeof serverAddr;
  int reuse = 1;
  setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  struct sockaddr_in localAddr;
  socklen_t localAddrLen = sizeof(localAddr);
  getsockname(clientSocket, (struct sockaddr *)&localAddr, &localAddrLen);
  char clientIP[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &(localAddr.sin_addr), clientIP, INET_ADDRSTRLEN);

  send(clientSocket, clientIP, strlen(clientIP) + 1, 0);
  printf("IP Sent\n");

  /* Record
  strcpy(buffer, inet_ntoa(serverAddr.sin_addr));
  send(clientSocket, buffer, 13, 0);
  */

  close(clientSocket);
  return 0;
}