#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);
    int bt[n],wt[n],tat[n],p[n];
    
    printf("Enter the Burst Times :\n");
    for (int i = 0; i < n; i++){
        p[i]=i+1;
        printf("Burst Time of Process %d: ", p[i]);
        scanf("%d",&bt[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(bt[j]>bt[j+1]) {
                int temp = bt[j+1];
                int ptemp = p[j+1];
                bt[j+1] = bt[j];
                p[j+1] = p[j];
                bt[j] = temp;
                p[j] = ptemp;
            }
        }
    }
    
    
    wt[0]=0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1]+bt[i-1];
    for (int i = 0; i < n; i++) tat[i] = wt[i]+bt[i];

    float avg_wt = 0;
    for(int i=0; i<n; i++) avg_wt+=wt[i];
    avg_wt=avg_wt/(float)n;

    float avg_tat = 0;
    for(int i=0; i<n; i++) avg_tat+=tat[i];
    avg_tat=avg_tat/(float)n;

    printf("P   BT  WT  TAT\n");
    for (int i = 0; i < n; i++){
        printf("%d   %d   %d   %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turn Around Time: %f\n", avg_tat);
}