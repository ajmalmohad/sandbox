#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void swap(int a, int b){
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
}

void display(){
    cout<<"\n";
    for(int elem: heap) cout<<elem<<" ";
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

int getSize(){
    return heap.size();
}

bool isEmpty(){
    return (getSize() == 0);
}

int getMax(){
    return isEmpty() ? 0 : heap[0];
}

void siftUp(int index){
    int elementIndex = index;
    int parentIndex = (elementIndex - 1)/2;
    while(parentIndex >= 0){
        if(heap[elementIndex] > heap[parentIndex]){
            swap(elementIndex, parentIndex);
            elementIndex = parentIndex;
            parentIndex = parent(elementIndex);
        }else{
            break;
        }
    }
}

void siftDown(int index){
    int leftIdx = left(index);
    int rightIdx = right(index);
    int n = getSize();
    while(index<n){
        int maxIdx;
        if(leftIdx<n && rightIdx<n) maxIdx = heap[rightIdx] > heap[leftIdx] ? rightIdx : leftIdx;
        else if(leftIdx<n) maxIdx = leftIdx;
        else if(rightIdx<n) maxIdx = rightIdx;
        else break;
        
        if(heap[maxIdx] > heap[index]){ 
            swap(index, maxIdx);
            index = maxIdx;
            leftIdx = left(index);
            rightIdx = right(index);
        }
        else break;
    }
}

void insert(int value){
    heap.push_back(value);
    siftUp(getSize()-1);
}

int extractMax(){
    if(isEmpty()) return 0;
    int maximum = heap[0];
    swap(0, getSize()-1);
    heap.pop_back();
    siftDown(0);
    return maximum;
}

int main(){
    insert(10);
    insert(20);
    insert(60);
    insert(5);
    insert(50);
    display();
    cout<<extractMax()<<" ";
    cout<<extractMax()<<" ";
    cout<<extractMax()<<" ";
    cout<<extractMax()<<" ";
    cout<<extractMax()<<" ";
    cout<<extractMax()<<" ";
    cout<<extractMax()<<" ";
}