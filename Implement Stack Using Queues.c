#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int size;
    int front;
    int rear;
    int* arr;
} MyStack;

void traversal(MyStack* stack){
    int i = stack->front+1;
    while(i<=stack->rear){
        printf("%d\t",stack->arr[i]);
        i++;
    }
    printf("\n");
}

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front=0;
    obj->rear=0;
    obj->size=100;
    obj->arr = (int*)malloc(sizeof(int)*obj->size);
    return obj;
}

bool myStackEmpty(MyStack* obj) {
    if(obj->front==obj->rear){
        return true;
    }
    return false;
}

bool myStackFull(MyStack* obj) {
    if((obj->rear+1)%obj->size==obj->front){
        return true;
    }
    return false;
}

void myStackPush(MyStack* obj, int x) {
    if(myStackFull(obj)){
        return;
    }
    else{
        obj->rear = (obj->rear+1)%obj->size;
        obj->arr[obj->rear] = x;
    }
}

int myStackTop(MyStack* obj) {
    if(myStackEmpty(obj))
    return -1;
    return obj->arr[obj->rear];
}

void myStackFree(MyStack* obj) {
    free(obj);
}

int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj))
    return -1;
    
    MyStack* obj2 = myStackCreate();

    printf("\nobj->rear = %d\nobj->front = %d\n",obj->rear,obj->front);

    while(obj->front<obj->rear){

        if(obj->front>0){
        myStackPush(obj2,obj->arr[obj->front]);
        printf("%d pushed into stack 2\n",obj->arr[obj->front]);
        }

        obj->front = (obj->front+1)%obj->size;
    }

    printf("\nobj->rear = %d\nobj->front = %d\n",obj->rear,obj->front);
    printf("\nobj2->rear = %d\nobj2->front = %d\nObj2:\n",obj2->rear,obj2->front);
    
    traversal(obj2);
    int val = obj->arr[obj->front];

    while(obj2->front<=obj2->rear){

        if(obj2->front>0)
        myStackPush(obj,obj2->arr[obj2->front]);
        
        obj2->front++;
    }
    traversal(obj);
    myStackFree(obj2);
    return val;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
 */
int main(){
    MyStack* stack = myStackCreate();
    myStackPush(stack,13);
    myStackPush(stack,58);
    myStackPush(stack,71);
    myStackPush(stack,43);
    traversal(stack);
    int removed = myStackPop(stack);
    printf("%d removed from stack\n", removed);
    myStackPush(stack,46);
    myStackPush(stack,75);
    traversal(stack);

    int top_element = myStackTop(stack);

    printf("\n%d is the top element of stack\n", top_element);
    return 0;
}