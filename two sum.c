#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int size){
    for(int i = 1; i<=size-1;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= key;}
}
int* copy(int* arr, int size){
    int* arr_copy = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++){
        arr_copy[i] = arr[i];
    }
    return arr_copy;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* numsCopy = copy(nums, numsSize);
    insertion_sort(nums,numsSize);
    int front = 0;
    int rear = numsSize - 1;
    int *ans = malloc(2 * sizeof(int));
    while (front < rear)
    {
        int sum = nums[front] + nums[rear];

        if (sum > target)
            rear--;
        else if (sum < target)
            front++;
        else
        {
            for(int i=0; i<numsSize; i++){
                if(numsCopy[i]==nums[front]){
                    ans[0] = i;
                }
                if(numsCopy[i]==nums[rear]){
                    ans[1] = i;
                }
            }
            *returnSize = 2;
            return ans;
        }
    }

    *returnSize = 0;
    return NULL;
}

int main()
{
    int arr[] = {3,2,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    int returnSize;
    int *array = twoSum(arr, size, target, &returnSize);

    if (array != NULL)
    {
        printf("%d %d\n", array[0], array[1]);
        free(array);
    }
    else
    {
        printf("No pair found.\n");
    }

    return 0;
}