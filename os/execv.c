#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
        printf("Parent Process Started\n");
        int pid = fork();
        if(pid==0){
                printf("Child Process Started\n");
                char* args[] = {"/bin/ls", "-l", 0};
                execv(args[0], args);
        }else{
                wait(0);
                printf("Parent Process Ended\n");
                exit(0);
        }
}