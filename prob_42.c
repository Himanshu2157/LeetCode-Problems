#include <stdlib.h>

typedef struct block{
    int* arr;
    int ptr;
    int sum;
    int size;
}stack;

void push(stack* s, int value){
    s->arr[s->ptr]=value;
    if(s->ptr==0){
        s->ptr++;
        return;
    }
    s->ptr++;
    s->sum+=value;
}

void pop(stack* s){
    s->ptr=s->sum=0;
}

int trap(int* height, int heightSize) {
    stack* s = (stack*)malloc(sizeof(stack));
    s->ptr = s->sum = 0;
    s->arr = (int*)malloc(heightSize*sizeof(int));

    int front, rear, not_started, length, breadth, rain_water;

    front=0; rear=1; not_started=1, rain_water=0;
    push(s, height[front]);

    if(heightSize==1 || heightSize==2){
        return 0;
    }

    while(front<heightSize){
        if(not_started && height[front]<height[rear]){
            pop(s);
            push(s,height[rear]);
            front++; rear++;
            continue;
        }

        not_started=0;

        if(rear == heightSize){
            pop(s);
            front++;
            rear=front+1;
            if(front==heightSize||rear==heightSize)
                break;
            push(s,height[front]);
        }

        if(height[front]<height[rear] || height[front]==height[rear]){
            length=height[front];
            breadth=rear-(front+1);
            rain_water += (length*breadth)-s->sum;
            pop(s);
            push(s,height[rear]);
            front=rear; rear++;
        }
        else{
            push(s,height[rear]);
            rear++;
        }
    }
    return rain_water;
}