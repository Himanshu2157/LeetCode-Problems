#include <stdio.h>

int min(int a, int b){
    if (a<b)
        return a;
    else if(b<a)
        return b;
    else
        return a;
}

int maxArea(int* height, int heightSize) {
    
    int front, rear, max_value, area, length, breadth , max_area=0;

    front = 0; rear = heightSize-1;
    
    while(front<rear){

        length = min(height[front], height[rear]);
    
        breadth = rear-front;
        
        area = length*breadth;

        if(area > max_area)
            max_area = area;

        if(height[front]>height[rear])
            rear--;

        else
            front++;
    }
    return max_area;
}