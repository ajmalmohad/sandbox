#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
        int pid, wid;
        pid=fork();
        if(pid==-1){
                perror("Error Occured");
                exit(0);
        }
        if(pid==0){
                printf("Child Process Executing\n");
                sleep(2);
                printf("Child Ended\n");
                exit(0);
        }else{
                printf("Parent Process Executing\n");
                wid=wait(0);
                if(wid==-1){
                        perror("Parent Waiting");
                }
                printf("Parent Ended\n");
                exit(0);
        }
}