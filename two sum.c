#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int front, rear;
    returnSize = (int*) malloc(2*sizeof(int));
    front=0; rear=numsSize-1;
    int found = 0;
    while(1){
        if (nums[front]+nums[rear]>target)
            rear--;
        else if (nums[front]+nums[rear]<target)
            front++;
        else if (nums[front]+nums[rear]==target){
            returnSize[0]=front;
            returnSize[1]=rear;
            found = 1;
            break;}
        else{
            break;}
    }
    if(found){
        return returnSize;
    }
    return NULL;
}

int main(){
    int arr[] = {11,45,56,78,91};
    int size = sizeof(arr)/sizeof(int);
    int sum = 123;
    int arr2[2];
    int* array = twoSum(arr,size,sum,arr2);
    printf("%d",*array);
    return 0;
}