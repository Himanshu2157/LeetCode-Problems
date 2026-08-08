#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyStack{
    int size;
    int front;
    int rear;
    int* arr;
    struct MyStack* Queue2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front=0;
    obj->rear=0;
    obj->size=100;
    obj->arr = (int*)malloc(sizeof(int)*obj->size);
    
    MyStack* obj2 = (MyStack*)malloc(sizeof(MyStack));
    obj2->front=0;
    obj2->rear=0;
    obj2->size=100;
    obj2->arr = (int*)malloc(sizeof(int)*obj->size);
    obj->Queue2 = obj2;
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
int peek(MyStack* obj){
    if (myStackEmpty(obj))
    return -1;

    return obj->arr[obj->front];
}
void enqueue(MyStack* obj, int x){
    if(myStackFull(obj)){
    return;}
    else{
    obj->rear = (obj->rear+1)%obj->size;
    obj->arr[obj->rear] = x;
    }
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj,x);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
int dequeue(MyStack* obj){
    if (myStackEmpty(obj)){
        return -1;
    }
    obj->front = (obj->front+1)%obj->size;
    return obj->arr[obj->front];
}
int myStackTop(MyStack* obj) {
    if (myStackEmpty(obj))
    return -1;
    
    int val;
    
    while (!myStackEmpty(obj)) {
        val = dequeue(obj);
        
        if(!myStackEmpty(obj)){
            myStackPush(obj->Queue2,val);
        }
        else {
            break;
        }
    }
    
    while(!myStackEmpty(obj->Queue2)){
        
        if(peek(obj->Queue2))
        myStackPush(obj,dequeue(obj->Queue2));
    }
    myStackPush(obj,val);
    
    return val;
}
int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj))
    return -1;
    
    int val;
    while (!myStackEmpty(obj)) {
        val = dequeue(obj);
        
        if(!myStackEmpty(obj)){
            myStackPush(obj->Queue2,val);
        }
        
        else {
            break;
        }
    }
    while(!myStackEmpty(obj->Queue2)){
        if(peek(obj->Queue2)!=val){
            myStackPush(obj,dequeue(obj->Queue2));}
        }
        
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
    void traversal(MyStack* obj){
        int i = obj->front+1;
        while(i<=obj->rear){
            printf("%d\t", obj->arr[i]);
            i++;
        }
        printf("\n");
    }

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
    printf("\n%d is the top element of stack\n\n", top_element);
    traversal(stack);
    return 0;
}