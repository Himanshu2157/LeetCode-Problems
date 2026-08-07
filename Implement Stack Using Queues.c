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
    obj->front=-1;
    obj->rear=-1;
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
    if(obj->rear==obj->size-1){
        return true;
    }
    return false;
}

void myStackPush(MyStack* obj, int x) {
    if(myStackFull(obj)){
        return;
    }
    else{
        obj->rear++;
        obj->arr[obj->rear] = x;
    }
}

int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj))
    return -1;
    
    MyStack* obj2 = myStackCreate();
    if(obj->front==-1)
        obj->front=0;
    while(obj->front<obj->rear){
        myStackPush(obj2,obj->arr[obj->front]);
        printf("%d pushed into stack 2\n",obj->arr[obj->front]);
        obj->front++;
    }
    printf("\nobj->rear = %d\nobj->front = %d\n",obj->rear,obj->front);
    printf("\nobj2->rear = %d\nobj2->front = %d\nObj2:\n",obj2->rear,obj2->front);
    traversal(obj2);
    int val = obj->arr[obj->front];
    while(obj2->front<=obj2->rear){
        if(obj2->front>-1)
        myStackPush(obj,obj2->arr[obj2->front]);
        obj2->front++;
    }
    traversal(obj);
    return val;
}

int myStackTop(MyStack* obj) {
    if(myStackEmpty(obj))
    return -1;
    return obj->arr[obj->rear];
}


void myStackFree(MyStack* obj) {
    free(obj);
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
    return 0;
}