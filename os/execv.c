#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
        int pid;
        printf("Parent Process Started\n");
        pid=fork();
        if(pid==0){
                printf("Child Process Started\n");
                char* args[] = {"/bin/ls", "-l", 0};
                execv(args[0], args);
        }else{
                wait(0);
                printf("Parent Process Ended\n");
        }
}