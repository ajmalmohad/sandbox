#include <stdio.h>

int main(){
    int n, m;

    printf("Enter Number of Blocks: ");
    scanf("%d", &n);
    int blocks[n];
    printf("Enter Block Sizes: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &blocks[i]);
    }

    printf("Enter Number of Processes: ");
    scanf("%d", &m);
    int process[m];
    printf("Enter Process Sizes: ");
    for (int i = 0; i < m; i++){
        scanf("%d", &process[i]);
    }

    int allocated[m];
    int count = 0;
    for (int i = 0; i < m; i++){
        allocated[i]=-1;
        int difference = 0;
        for (int j = 0; j < n; j++){
            if(process[i]<=blocks[j]){
                if(blocks[j]-process[i]>difference) {
                    difference=blocks[j]-process[i];
                    allocated[i]=j+1;
                }
            }
        }
        if(allocated[i]!=-1){
            count++;
            blocks[allocated[i]-1]-=process[i];
            printf("%d : %d : %d\n", process[i], allocated[i], blocks[allocated[i]-1]);
        }else{
            printf("%d : %s\n", process[i], "Not Allocated");
        }
    }
    
}