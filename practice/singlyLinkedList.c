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
} myLinkedList;

void init();
void display();
void insertAtTail(int value);
void insertAtHead(int value);
void insertAtIndex(int value, int index);
void deleteAtTail();
void deleteAtHead();
void deleteAtIndex(int index);

int main(){
    init();
    int choice;
    
    do{
        printf("\n1. Insert at Head\n2. Insert at Tail \n3. Insert At Index");
        printf("\n4. Delete at Head \n5. Delete at Tail \n6. Delete At Index");
        printf("\n7. Display \n8. Exit \n");
        printf("Enter a Choice :");
        scanf("%d",&choice);
        int element, index;
        switch (choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&element);
                insertAtHead(element);
                break;
            case 2:
                printf("Enter Value: ");
                scanf("%d",&element);
                insertAtTail(element);
                break;
            case 3:
                printf("Enter Value: ");
                scanf("%d",&element);
                printf("Enter Index: ");
                scanf("%d",&index);
                insertAtIndex(element,index);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter Index: ");
                scanf("%d",&index);
                deleteAtIndex(index);
                break;
            case 7:
                display();
                break;
            case 8: 
                break;
            default: 
                printf("Invalid Input");
                choice = 8;
                break;
        }

    }while(choice!=8);
}

void init(){
    myLinkedList.size = 0;
    myLinkedList.head = NULL;
    myLinkedList.tail = NULL;
}

void insertAtTail(int value){
    struct Node *node;
    node=(struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    if(myLinkedList.head == NULL){
        myLinkedList.head = node;
        myLinkedList.tail = node;
    }else{
        myLinkedList.tail->next = node;
        myLinkedList.tail = myLinkedList.tail->next;
    }
    myLinkedList.size++;
}

void insertAtHead(int value){
    struct Node *node;
    node=(struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    if(myLinkedList.head == NULL){
        myLinkedList.head = node;
        myLinkedList.tail = node;
    }else{
        node->next = myLinkedList.head;
        myLinkedList.head = node;
    }
    myLinkedList.size++;
}

void insertAtIndex(int value, int index){
    if(index > myLinkedList.size || index < 0) { printf("Invalid Index!\n"); return; }
    else if(index == 0) { insertAtHead(value); return; }
    else if(index == myLinkedList.size) { insertAtTail(value); return; }

    struct Node* temp = myLinkedList.head;
    for (int i = 0; i < index-1; i++) temp = temp->next;
    
    struct Node *node;
    node=(struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->next = temp->next;
    temp->next = node;

    myLinkedList.size++;
}

void display(){
    if(myLinkedList.size == 0){
        printf("Linked List is Empty\n");
    }else{
        struct Node* temp = myLinkedList.head;
        while(temp){
            printf("%d -> ",temp->value);
            temp = temp->next;
        }
        printf("Null\n");
    }
}

void deleteAtTail(){
    if(myLinkedList.size<1) return;
    if(myLinkedList.size == 1) { 
        myLinkedList.head = NULL;
        myLinkedList.tail = NULL;
        myLinkedList.size=0;
        return;
    }

    struct Node* temp = myLinkedList.head;
    while(temp->next->next){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    myLinkedList.size--;
}

void deleteAtHead(){
    if(myLinkedList.size <= 1) { 
        deleteAtTail();
        return;
    }
    
    struct Node* temp = myLinkedList.head;
    myLinkedList.head = myLinkedList.head->next;
    free(temp);
    myLinkedList.size--;
}

void deleteAtIndex(int index){
    printf("%d", index);
}