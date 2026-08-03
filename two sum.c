#include <stdio.h>

int main(){
    int arr[] = {11,45,56,78,91};
    int size = sizeof(arr)/sizeof(int);
    int front, rear;
    int sum = 123;
    front=0; rear=size-1;
    while(1){
        if (arr[front]+arr[rear]>sum)
            rear--;
        else if (arr[front]+arr[rear]<sum)
            front++;
        else if (arr[front]+arr[rear]==sum){
            printf("Sum found at index: %d and %d\n", front, rear);
            break;}
        else{
            printf("No index sum matches");
            break;}
    }
    return 0;
}