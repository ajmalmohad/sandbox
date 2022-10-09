#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
        int pid, wid;
        pid = fork();
        if(pid==-1){
                perror("Error Occured\n");
        }
        if(pid==0){
                printf("Child Process Started\n");
                sleep(2);
                printf("Child Process Ended\n");
        }else{
                printf("Parent Process Started\n");
                wid = wait(0);
                if(wid==-1) perror("Parent Still Waiting");
                printf("Parent Process Completed\n");
        }
}