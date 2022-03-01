#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct SinglyLinkedList{
    int size;
    struct Node* head;
    struct Node* tail;
} myQueue;

void init();
void display();
void enqueue(int value);
void dequeue();


int main(){
    init();
    int choice;
    
    do{
        printf("\n1. Enqueue\n2. Dequeue \n3. Display \n4. Exit \n");
        printf("Enter a Choice :");
        scanf("%d",&choice);
        int element, index;
        switch (choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default: 
                printf("Invalid Input");
                choice = 4;
                break;
        }
    }while(choice!=4);
}

void init(){
    myQueue.size = 0;
    myQueue.head = NULL;
    myQueue.tail = NULL;
}

void enqueue(int value){
    struct Node *node;
    node=(struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    if(myQueue.head == NULL){
        myQueue.head = node;
        myQueue.tail = node;
    }else{
        node->next = myQueue.head;
        myQueue.head = node;
    }
    myQueue.size++;
}

void dequeue(){
    if(myQueue.size<1) return;
    if(myQueue.size == 1) { 
        myQueue.head = NULL;
        myQueue.tail = NULL;
        myQueue.size=0;
        return;
    }
    struct Node* temp = myQueue.head;
    while(temp->next->next) temp = temp->next;
    
    free(temp->next);
    temp->next = NULL;
    myQueue.size--;
}

void display(){
    if(myQueue.size == 0){
        printf("Linked List is Empty\n");
    }else{
        struct Node* temp = myQueue.head;
        while(temp){
            printf("%d -> ",temp->value);
            temp = temp->next;
        }
        printf("Null\n");
    }
}

