#include <stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main(){
    int cost[20][20];
    int nodes, count = 0;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter Cost Matrix: ");

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            scanf("%d", &cost[i][j]);
            cost[i][i] = 0;
            rt[i].dist[j] = cost[i][j];
            rt[i].from[j] = j;
        }
    }

    do {
        count = 0;
        for(int i=0; i<nodes; i++){
            for(int j=0; j<nodes; j++){
                for(int k=0; k<nodes; k++){
                    if(rt[i].dist[j] > cost[i][k]+rt[k].dist[j]){
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    }while(count != 0);

    for(int i=0; i<nodes; i++){
        printf("\n\nFor router %d\n", i+1);
        for(int j=0; j<nodes; j++){
            printf("\nnode %d via %d Distance %d", j+1, rt[i].from[j]+1, rt[i].dist[j]);
        }
    }

    printf("\n");
}

