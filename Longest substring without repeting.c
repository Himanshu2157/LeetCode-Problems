#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct letter{
    char c;
    int count;
    struct letter* next;
}letter;
typedef struct substr{
    char* str;
    int len;
    struct subtstr* next;
}substr;

int letter_do_not_exist(letter* ltr, char ch){
    while(ltr!=NULL){
        if(ltr->c == ch){
            return 0;
        }
        ltr=ltr->next;
    }
    return 1;
}
void create_node_letter(letter* ltr, char ch){
    if(ltr->next==NULL){
        ltr->c=ch;
        return;
    }
    letter* ptr = (letter*)malloc(sizeof(letter));
    ptr->c=ch;
    ptr->next = NULL;
    while(ltr->next!=NULL){
        ltr=ltr->next;
    }
    ltr->next = ptr;
} 
void create_node_string(substr* str, char* s){
    if(str->next==NULL){
        str->str = s;
        return;
    }
    substr* ptr = (substr*)malloc(sizeof(substr));
    ptr->str=str;
    ptr->next = NULL;
    while(str->next!=NULL){
        str=str->next;
    }
    str->next = ptr;
} 
void reset_letter_count(letter* ltr){
    while(ltr!=NULL)
        ltr->count = 0;
}
void free_letter_list(letter* ltr){
    if(ltr==NULL)
        return;
    free_list(ltr->next);
    free(ltr);
}
void free_substr_list(substr* ltr){
    if(ltr==NULL)
        return;
    free_list(ltr->next);
    free(ltr);
}

int lengthOfLongestSubstring(char* s) {
    letter* ltr = (letter*)malloc(sizeof(letter));
    ltr->c = s[0];
    ltr->next = NULL;
    letter* str = (substr*)malloc(sizeof(substr));
    str->next = NULL;

    for(int i=0;s[i]!='\0';i++){
        if(letter_do_not_exist(ltr, s[i]))
            create_node_letter(ltr,s[i]);
    }

    int front,rear;
    front=rear=0;