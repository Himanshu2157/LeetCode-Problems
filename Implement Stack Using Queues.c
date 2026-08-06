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


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front=-1;
    obj->rear=-1;
    obj->size=5;
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

MyStack* myStackPop(MyStack* obj) {
    if (myStackEmpty(obj))
    return obj;
    
    MyStack* obj2 = myStackCreate();
    if(obj->front==-1)
        obj->front=0;
    while(obj->front<obj->rear){
        myStackPush(obj2,obj->arr[obj->front]);
        printf("%d pushed into stack\n",obj->arr[obj->front]);
        obj->front++;
    }
    int val = obj->arr[obj->front];
    printf("%d removed from stack\n", val);
    free(obj);
    return obj2;
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
void traversal(MyStack* stack){
    int i = 0;
    while(i<=stack->rear){
        printf("%d\t",stack->arr[i]);
        i++;
    }
    printf("\n");
}
int main(){
    MyStack* stack = myStackCreate();
    printf("%d\n",myStackEmpty(stack));
    myStackPush(stack,13);
    // stack = myStackPop(stack);
    myStackPush(stack,58);
    myStackPush(stack,71);
    myStackPush(stack,43);
    printf("%d\n",myStackFull(stack));
    myStackPush(stack,43);
    printf("%d\n",myStackFull(stack));
    myStackPush(stack,43);
    printf("%d\n",myStackFull(stack));
    traversal(stack);
    // stack = myStackPop(stack);
    traversal(stack);
    return 0;
}