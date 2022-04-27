#include <stdio.h>

void merge(int* arr, int start, int end, int mid){
    int n1 = (mid-start)+1;
    int n2 = end-mid;
    int ar1[n1];
    int ar2[n2];

    for (int i = start; i <=mid; i++) ar1[i-start]=arr[i];
    for (int i = mid+1; i <=end; i++) ar2[i-(mid+1)]=arr[i];

    int i=0, j=0, k=start;
    while (i<n1 && j<n2){
        if(ar1[i]<ar2[j]){
            arr[k]=ar1[i];
            i++;
            k++;
        }else{
            arr[k]=ar2[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k] = ar1[i];
        i++;
        k++;
    } 

    while(j<n2){
        arr[k] = ar2[j];
        j++;
        k++;
    }
    
}

void mergeSort(int* arr, int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end, mid);
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0,n-1);
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
}