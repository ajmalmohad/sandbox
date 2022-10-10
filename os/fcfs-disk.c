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

    float total = 0;
    total += abs(start - requests[0]);
    for (int i = 1; i < n; i++){
        total += abs(requests[i-1]-requests[i]);
    }
    
    printf("Total Seek Time: %f\n", total);
    printf("Avergae Seek Time: %f\n", total/(float)n);
}