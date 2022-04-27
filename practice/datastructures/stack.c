#include <stdio.h>
#include <stdlib.h>
 
struct Stack{
    int top;
    int capacity;
    int* array;
};
 
struct Stack* createStack( int capacity ){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack) return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity *sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack)
    return stack->top == -1 ;

char peek(struct Stack* stack)
    return stack->array[stack->top];

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(struct Stack* stack, char op)
    stack->array[++stack->top] = op;

void print(struct Stack* stack)
    for (int i = 0; i <= stack->top; i++) printf("%d ", stack->array[i]);
    

int main(){
    struct Stack *stack = createStack(10);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    print(stack);
}