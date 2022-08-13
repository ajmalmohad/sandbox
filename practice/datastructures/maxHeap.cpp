#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void swap(int a, int b){
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
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

void insert(int value){
    heap.push_back(value);
    siftUp(heap.size()-1);
}


bool isEmpty(){
    return (heap.size() == 0);
}

int getMax(){
    return isEmpty() ? 0 : heap[0];
}

void display(){
    cout<<"\n";
    for(int elem: heap) cout<<elem<<" ";
    cout<<"\n";
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(5);
    insert(50);
    display();
    cout<<"\nMax is: "<<getMax();
    cout<<"\nIs Empty? "<<isEmpty();
}