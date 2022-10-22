#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, start;
    printf("Enter Number of Requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter Request Positions: ");
    for (int i = 0; i < n; i++) scanf("%d", &requests[i]);
    printf("Enter Starting Position: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(requests[j]>requests[j+1]){
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d ", requests[i]);
    }
    
    

    float total = 0;
    
    printf("Total Seek Time: %f\n", total);
    printf("Avergae Seek Time: %f\n", total/(float)n);
}