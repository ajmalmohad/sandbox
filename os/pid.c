#include <stdio.h>
#include <stdlib.h>

int main(){
        int pid;
        pid = getpid();
        printf("Child: %d\n", pid);
        pid = getppid();
        printf("Parent: %d\n", pid);
}