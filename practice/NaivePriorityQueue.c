#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int n;

void enqueue();
int dequeue();
void display();

struct Node{
    int item;
    int priority;
} queue[100];

int main() {
    printf("\nEnter the Size of Queue:");
    scanf("%d",&n);
    printf("\nPriority Queue");
    
    int ch;
    do{
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
        printf("\nEnter choice:");
        
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default:printf("\nInvalid choice!!"); break;
        }
    }while(ch!=4);

    return 0;
}

void enqueue()
{
    if(rear==n-1){
        printf("Queue is full!\n");
    }else{
        rear++;
        if(front==-1) front++;
        
        int val;
        printf("\nEnter the Item:");
        scanf("%d",&val);
        queue[rear].item=val;

        int pr;
        printf("Enter the Priority:");
        scanf("%d",&pr);
        queue[rear].priority=pr;

        for(int i=front;i<rear;i++){
            for(int j=i+1;j<rear;j++){
                if(queue[i].priority<queue[j].priority){
                    struct Node temp=queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }
}

int dequeue(){

    if(front==-1){
        printf("\nQueue is empty");
        return 0;
    }else{
        int item = queue[front].item;
        int priority = queue[front].priority;
        printf("\nItem to be deleted is:%d \nRespective Priority to be deleted is:%d",item,priority);

        //If only One Element is Present
        if(front==rear) rear=front=-1;
        else front++;
    }

}
void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }else{
        for(int i=front;i<=rear;i++){
            printf("\nElement %d \tPriority %d", queue[i].item,queue[i].priority);
        }
    }  
}