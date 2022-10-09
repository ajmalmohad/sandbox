#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
    key_t key = 12345;
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    char* str = shmat(shmid,0,0);
    gets(str);
}