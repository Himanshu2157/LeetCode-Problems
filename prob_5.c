#include <string.h>

int matching(char* s, int front, int rear){
    if(front>=rear)
        return 1;
    if(s[front]!=s[rear])
        return 0;
    return matching(s,front+1,rear-1);
}

char* substring(char* s, int front, int length){
    char* ptr = (char*)malloc(length+1);

    strncpy(ptr, s + front, length);
    ptr[length] = '\0';
    return ptr;
}

char* longestPalindrome(char* s) {
    int front, rear, length_of_palindrome;
    char* palindrome;
    front=0; rear=strlen(s)-1; length_of_palindrome=1; palindrome=&s[rear];

    int matched;
    
    while(front<strlen(s)){
        while(rear!=front){
            matched=matching(s,front,rear);

            if(matched && length_of_palindrome<(rear-front+1)){
                length_of_palindrome = rear-front+1;
                palindrome=substring(s,front,length_of_palindrome);
            }
            rear--;
        }
        rear=strlen(s)-1; front++;
    }
}