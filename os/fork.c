#include<stdio.h>
#include<stdlib.h>

int main(){
        int id = fork();
        printf("id: %d\n", id);
        return 0;
}