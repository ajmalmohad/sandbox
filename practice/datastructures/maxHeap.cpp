#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
}

void display(vector<int>& arr){
    cout<<"\nHeap Displaying: ";
    for(int elem: arr) cout<<elem<<" ";
    cout<<"\n";
}

int parent(int index){
    return (index - 1)/2;
}

int left(int index){
    return (2*index)+1;
}

int right(int index){
    return (2*index)+2;
}

int getSize(vector<int>& arr){
    return arr.size();
}

bool isEmpty(vector<int>& arr){
    return (getSize(arr) == 0);
}

int getMax(vector<int>& arr){
    return isEmpty(arr) ? 0 : arr[0];
}

void siftUp(vector<int>& arr, int index){
    int elementIndex = index;
    int parentIndex = (elementIndex - 1)/2;
    while(parentIndex >= 0){
        if(arr[elementIndex] > arr[parentIndex]){
            swap(arr, elementIndex, parentIndex);
            elementIndex = parentIndex;
            parentIndex = parent(elementIndex);
        }else{
            break;
        }
    }
}

void siftDown(vector<int>& arr, int index){
    int leftIdx = left(index);
    int rightIdx = right(index);
    int n = getSize(arr);
    while(index<n){
        int maxIdx;
        if(leftIdx<n && rightIdx<n) maxIdx = arr[rightIdx] > arr[leftIdx] ? rightIdx : leftIdx;
        else if(leftIdx<n) maxIdx = leftIdx;
        else if(rightIdx<n) maxIdx = rightIdx;
        else break;
        
        if(arr[maxIdx] > arr[index]){ 
            swap(arr, index, maxIdx);
            index = maxIdx;
            leftIdx = left(index);
            rightIdx = right(index);
        }
        else break;
    }
}

void insert(vector<int>& arr, int value){
    arr.push_back(value);
    siftUp(arr, getSize(arr)-1);
}

int extractMax(vector<int>& arr){
    if(isEmpty(arr)) return 0;
    int maximum = arr[0];
    swap(arr, 0, getSize(arr)-1);
    arr.pop_back();
    siftDown(arr, 0);
    return maximum;
}

void extractAllMax(vector<int>& arr){
    cout<<"\nHeap Extraction: ";
    int n = getSize(arr);
    for (int i = 0; i < n; i++) cout<<extractMax(arr)<<" ";
    cout<<"\n";
}

void heapify(vector<int>& arr){
    for (int i = getSize(arr)/2; i >=0 ; i--){
        siftDown(arr, i);
    }
}

int main(){
    vector<int> heap = {10,20,60,5,50,100};
    heapify(heap);
    display(heap);
    extractAllMax(heap);
}