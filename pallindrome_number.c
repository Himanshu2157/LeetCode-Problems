#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPalindrome(int x) {
    
}
int main(){
    int x = 1;
    int count = x;
    int power = 0;
    do{
        power++;
        count/=10;
    }while(count/10!=0);
    
    count = x;
    int new=0;
    
    do{
        double ten_place = pow(10,power);
        printf("%d\n\n", count);
        new += (count%10)*ten_place;
        power--;
        count/=10;
    }while(count!=0);
    
    if (new==x){
        // printf("Palindrome");
        return true;
    }
    else{
        // printf("Not Palindrome");
        return false;
    }
    printf("%d\n\n%d\n\n", count, new);
    // int power=0;
    
    
    // while(x/10 != 0){
    //     printf("%d\n", x);
    //     pow++;
    //     x/=10;
    // }
    return 0;
}