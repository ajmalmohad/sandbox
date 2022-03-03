#include <stdio.h>

int main(){
    int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
    for (int i = 0; i < 10; i++){
        int minIndex = i;
        for (int j = i; j < 10; j++) if(arr[j]< arr[minIndex]) minIndex=j;
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
}