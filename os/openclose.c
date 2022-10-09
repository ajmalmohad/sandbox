#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(){
        char name[256];
        printf("Enter Directory Name: ");
        scanf("%s", name);

        DIR *directory = opendir(name);
        if(directory==NULL){
                printf("Not Found\n");
        }else{
                struct dirent* entry;
                while(entry=readdir(directory)){
                        printf("%s\n", entry->d_name);
                }
        }
        closedir(directory);
}