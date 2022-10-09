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
        for (int j = 0; j < n; j++){
            if(process[i]<=blocks[j]){
                allocated[i]=j+1;
                blocks[j]-=process[i];
                count++;
                break;
            }
        }
    }

    printf("Allocated! %d\n", m);
    for (int i = 0; i < m; i++){
        if(allocated[i]==-1)  printf("%d : %s\n", process[i], "Not Allocated");
        else printf("%d : %d\n", process[i], allocated[i]);
    }
    
    
}