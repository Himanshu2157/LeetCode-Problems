#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int front = 0;
    int rear = numsSize - 1;

    while (front < rear)
    {
        int sum = nums[front] + nums[rear];

        if (sum > target)
            rear--;
        else if (sum < target)
            front++;
        else
        {
            int *ans = malloc(2 * sizeof(int));
            ans[0] = front;
            ans[1] = rear;
            *returnSize = 2;
            return ans;
        }
    }

    *returnSize = 0;
    return NULL;
}

int main()
{
    int arr[] = {11,45,56,78,91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 123;

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