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
} myStack;

void init();
void display();
void push(int value);
void pop();

int main(){
    init();
    int choice;
    do{
        printf("\n1. Push\n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter a Choice :");
        scanf("%d",&choice);
        int element, index;
        switch (choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&element);
                push(element);
                break;
            case 2:
                pop();
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
    myStack.size = 0;
    myStack.head = NULL;
    myStack.tail = NULL;
}

void push(int value){
    struct Node *node;
    node=(struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    if(myStack.head == NULL){
        myStack.head = node;
        myStack.tail = node;
    }else{
        myStack.tail->next = node;
        myStack.tail = myStack.tail->next;
    }
    myStack.size++;
}


void display(){
    if(myStack.size == 0){
        printf("Linked List is Empty\n");
    }else{
        struct Node* temp = myStack.head;
        while(temp){
            printf("%d -> ",temp->value);
            temp = temp->next;
        }
        printf("Null\n");
    }
}

void pop(){
    if(myStack.size<1) return;
    if(myStack.size == 1) { 
        myStack.head = NULL;
        myStack.tail = NULL;
        myStack.size=0;
        return;
    }

    struct Node* temp = myStack.head;
    while(temp->next->next){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    myStack.size--;
}