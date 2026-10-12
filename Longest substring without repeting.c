#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct queue{
    char* Sub;
    int front;
    int rear;
    int size;
}queue;

int Compare(queue* q, char ch){
    if(q->front==q->rear)
        return 0;

    int i = q->front;

    while(i!=q->rear){
        if(q->Sub[i]==ch)
            return 1;

        i=(i+1)%q->size;
    }

    return 0;
}

void enqueue(queue* q, char ch){
    q->Sub[q->rear] = ch;
    q->rear=(q->rear+1)%q->size;
}

void dequeue(queue* q){
    q->front=(q->front+1)%q->size;
}

int length(queue* q){
    if(q->front>q->rear || q->front==q->rear)
        return q->size + q->rear - q->front;

    return q->rear - q->front;
}

int lengthOfLongestSubstring(char* s){
    queue* SubStr = (queue*)malloc(sizeof(queue));

    SubStr->Sub = (char*)malloc(strlen(s)*sizeof(char));
    SubStr->front = SubStr->rear = 0;
    SubStr->size = strlen(s);

    int rear, longest;
    rear = longest = 0;

    int matching;

    while (s[rear]!='\0')
    {
        matching = Compare(SubStr,s[rear]);

        if(matching){
            if(longest<length(SubStr))
                longest = length(SubStr);
            dequeue(SubStr);
        }
        else{
            enqueue(SubStr, s[rear]);
            rear++;
        }
    }

    if(longest<length(SubStr))
        longest = length(SubStr);
    
    free(SubStr->Sub);
    free(SubStr);
    return longest;
}

int main(){
    printf("%d", lengthOfLongestSubstring("a"));

    return 0;
}