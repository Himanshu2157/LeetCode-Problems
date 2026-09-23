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
    struct substr* next;
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
    letter* ptr = (letter*)malloc(sizeof(letter));
    ptr->c=ch;
    ptr->next = NULL;
    while(ltr->next!=NULL){
        ltr=ltr->next;
    }
    ltr->next = ptr;
} 
void create_node_string(substr* str, char* s, int length){

    substr* ptr = (substr*)malloc(sizeof(substr));
    ptr->str = s;
    ptr->len=length;

    ptr->next = NULL;
    while(str->next!=NULL){
        str=str->next;
    }
    str->next = ptr;
} 
void reset_letter_count(letter* ltr){
    while(ltr!=NULL){
        ltr->count = 0;
        ltr=ltr->next;}
}
void free_letter_list(letter* ltr){
    if(ltr==NULL)
        return;
    free_letter_list(ltr->next);
    free(ltr);
}
void free_substr_list(substr* ltr){
    if(ltr==NULL)
        return;
    free_substr_list(ltr->next);
    free(ltr);
}
int match_letter(letter* ltr, char ch){
    while(ltr!=NULL){
    if(ltr->c==ch){
        if(ltr->count){
            break;
        }
        ltr->count=1;
        return 1;
    }
    ltr=ltr->next;
    }
    return 0;
}
int max(substr* str){
    int max=-1;
    while(str!=NULL){
        if( max < str->len){
            max = str->len;
        }
        str=str->next;
    }
    return max;
}

int lengthOfLongestSubstring(char* s) {
    letter* ltr = (letter*)malloc(sizeof(letter));
    ltr->c = s[0];
    ltr->next = NULL;
    substr* word = (substr*)malloc(sizeof(substr));
    word->next = NULL;
    int substring_index;

    for(int i=0;s[i]!='\0';i++){
        if(letter_do_not_exist(ltr, s[i]))
            create_node_letter(ltr,s[i]);
    }

    int front,rear;
    front=rear=0;
    int match_letter_value;
    while(s[rear]!='\0'){
        match_letter_value=match_letter(ltr,s[rear]);
        if(match_letter_value){
            rear++;
        }
        else{
            int length_of_substr=rear-front+1;
            char substring[length_of_substr];
            substring_index=0;
            
            for(int i = front; i< rear; i++){
                substring[substring_index] = s[i];
                substring_index++;
            }
            
            substring[length_of_substr-1]='\0';
            
            if(word->next==NULL){
                word->len=rear-front+1;
                word->str=substring;
            }
            else{
                create_node_string(word,substring,length_of_substr);
            }
            reset_letter_count(ltr);
            match_letter_value=match_letter(ltr,s[rear]);
            front=rear;
            rear++;
        }
    }
        int max_value=max(word);
        free_letter_list(ltr);
        free_substr_list(word);
        return max_value;
}