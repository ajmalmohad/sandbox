#include <stdio.h>

void swap(int* arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partitionEnd(int* arr, int start, int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j=start; j<end; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr, i+1, end);
    return i+1;
}

int partitionStart(int* arr, int start, int end){
    int pivot = arr[start];
    int i = end+1;
    for(int j=end; j>start; j--){
        if(arr[j]>pivot){
            i--;
            swap(arr,i,j);
        }
    }
    swap(arr, i-1, start);
    return i-1;
}

void quickSort(int* arr, int start, int end){
    if(start<end){
        int pivotIndex = partitionStart(arr, start, end);
        quickSort(arr, start, pivotIndex-1);
        quickSort(arr, pivotIndex+1, end);
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    // int arr[] = {19,8,77,6,10,4,3,100,1,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0,n-1);
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
}