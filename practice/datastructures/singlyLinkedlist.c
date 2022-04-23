#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LinkedList{
    struct Node* head;
    struct Node* tail;
}  myLinkedlist;

void insertAtHead(int element){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;
    
    if(myLinkedlist.head == NULL){
        myLinkedlist.head = newnode;    
        myLinkedlist.tail = newnode;
    }else{
       newnode->next = myLinkedlist.head;
       myLinkedlist.head = newnode;
    }
}

void insertAtTail(int element){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;
    
    if(myLinkedlist.head == NULL){
        myLinkedlist.head = newnode;    
        myLinkedlist.tail = newnode;
    }else{
       myLinkedlist.tail->next = newnode;
       myLinkedlist.tail = newnode;
    }
}

void insertAtPosition(int element, int index){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;

    if (index==0) insertAtHead(element);
    else{
        struct Node* temp = myLinkedlist.head;
        int i = 0;
        while(temp != NULL && i<index-1){
            i++;
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display(){
    if(myLinkedlist.head == NULL) printf("Empty");
    else{
        struct Node* temp = myLinkedlist.head;
        printf("\n");
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("Null\n");
    }
}

int main(){
    myLinkedlist.head = NULL;
    myLinkedlist.tail = NULL;

    int choice=0, element, index;
    do{
        printf("1.Exit \n2.Insert at Head \n3.Insert at Tail \n4.Display\n5.Insert at Index\n");
        scanf("%d", &choice);
        switch (choice){
            case 1: printf("Exitted\n");
                    break;
            case 2:
                    printf("\nEnter Element to be inserted: ");
                    scanf("%d",&element);
                    insertAtHead(element);
                    break;
            case 3:
                    printf("\nEnter Element to be inserted: ");
                    scanf("%d",&element);
                    insertAtTail(element);
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    printf("\nEnter Element to be inserted: ");
                    scanf("%d",&element);
                    printf("\nEnter Index to be inserted: ");
                    scanf("%d",&index);
                    insertAtPosition(element, index);
                    break;
            default:
                    printf("\nInvalid Option\n");
                    break;
        }
    }while(choice != 1);
}