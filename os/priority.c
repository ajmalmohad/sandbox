#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);
    int bt[n],wt[n],tat[n],p[n], pr[n];
    
    printf("Enter the Burst Times :\n");
    for (int i = 0; i < n; i++){
        p[i]=i+1;
        printf("Burst Time && Priority of Process  %d: ", p[i]);
        scanf("%d",&bt[i]);
        scanf("%d",&pr[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(pr[j]>pr[j+1]) {
                int temp = pr[j+1];
                int ptemp = p[j+1];
                int btemp = bt[j+1];
                pr[j+1] = pr[j];
                p[j+1] = p[j];
                bt[j+1] = bt[j];
                pr[j] = temp;
                p[j] = ptemp;
                bt[j] = btemp;
            }
        }
    }
    
    
    wt[0]=0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1]+bt[i-1];
    for (int i = 0; i < n; i++) tat[i] = wt[i]+bt[i];

    float avg_wt = 0;
    for(int i=0; i<n; i++) avg_wt+=wt[i];
    avg_wt=avg_wt/n;

    float avg_tat = 0;
    for(int i=0; i<n; i++) avg_tat+=tat[i];
    avg_tat=avg_tat/n;

    printf("P   BT  WT  TAT\n");
    for (int i = 0; i < n; i++){
        printf("%d   %d   %d   %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turn Around Time: %f\n", avg_tat);
}