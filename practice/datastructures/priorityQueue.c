#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    int priority;
} *q[4];

int top=-1;
int n=4;

void enqueue(int value, int priority){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value = value;
    newnode->priority = priority;
    if(top==n-1){
        printf("\nOverflow\n");
    }else{
        top++;
        q[top] = newnode;
        printf("%d %d",q[top]->priority, q[top]->value);
    }
}

void dequeue(){
    if(top==-1) printf("Underflow");
    else{
        int p = q[0]->priority;
        int k = 0;
        struct Node* pn = q[0];
        for (int i = 0; i <= top; i++){
            if(q[i]->priority>p){
                p = q[i]->priority;
                pn = q[i];
                k=i;
            }
        }
        
        for (int i = k; i < n-1; i++){
            q[i] = q[i+1];
        }
        q[top] = NULL;
        top--;

        printf("Deleted %d with Priority %d", pn->value,pn->priority);
        free(pn);
    }
}

int main(){
    int choice, value, priority;
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter value :");
                scanf("%d", &value);
                printf("Enter priority :");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;

        case 2: dequeue();
                break;
        
        default:
                break;
        }
    } while (choice != 3);
}