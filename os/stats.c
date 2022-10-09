#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(){
        char path[10];
        struct stat nfile;
        printf("Enter filename: ");
        scanf("%s", path);
        stat(path, &nfile);
        printf("User Id : %d\n", nfile.st_uid);
        printf("Block Size : %ld\n", nfile.st_blksize);
        printf("Access Time : %ld\n", nfile.st_atime);
        printf("Mode : %d\n", nfile.st_mode);
        printf("Size : %ld\n", nfile.st_nlink);
}