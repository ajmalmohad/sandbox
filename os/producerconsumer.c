#include <stdio.h>
#include <stdlib.h>
int buffer;
int quantity=0;
int mutex=1;

int signal(int n){
    return ++n;
}

int wait(int n){
    return --n;
}

void produce(){
    if(quantity==buffer) {
        printf("Buffer Full\n");
        return;
    }
    if(mutex){
        mutex = wait(mutex);
        quantity++;
        printf("Producer Produces Item %d!\n", quantity);
        mutex = signal(mutex);
    }
}

void consume(){
    if(quantity==0) {
        printf("Buffer Empty\n");
        return;
    }
    if(mutex){
        mutex = wait(mutex);
        printf("Consumer Consumes Item %d!\n", quantity);
        quantity--;
        mutex = signal(mutex);
    }
}

int main(){
    int choice;
    printf("Enter buffer size: ");
    scanf("%d", &buffer);
    printf("\n1.Produce\n2.Consume\n3.Quit\n");
    do{
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: produce(); break;
        case 2: consume(); break;
        default: break;
        }
    } while (choice!=3);
}