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

int letter_do_not_exist(letter* ltr, char ch){  //checks if character had appeared in substring
    while(ltr!=NULL){
        if(ltr->c == ch){
            return 0;
        }
        ltr=ltr->next;
    }
    return 1;
}
void create_node_letter(letter* ltr, char ch){    //creates new node for a different character

    if(ltr->c=='\0'){
        ltr->c=ch;
        return;
    }

    letter* ptr = (letter*)malloc(sizeof(letter));
    ptr->c=ch;
    ptr->count=0;
    ptr->next = NULL;

    while(ltr->next!=NULL){
        ltr=ltr->next;
    }

    ltr->next = ptr;
} 
void create_node_string(substr* str, char* s, int length){   //creates new node for a different character

    if(str->str==""){
        str->len=length;
        str->str=s;
        return;
    }

    substr* ptr = (substr*)malloc(sizeof(substr));
    ptr->str = s;
    ptr->len=length;
    ptr->next = NULL;

    while(str->next!=NULL){
        str=str->next;
    }

    str->next = ptr;
} 
void reset_letter_count(letter* ltr){  //if a rrepeated char appears, resets the count of chars to 0
    while(ltr!=NULL){
        ltr->count = 0;
        ltr=ltr->next;}
}
void free_letter_list(letter* ltr){  //free the character linked list
    if(ltr==NULL)
        return;
    free_letter_list(ltr->next);
    free(ltr);
}
void free_substr_list(substr* ltr){   //free the substring linked list
    if(ltr==NULL)
        return;
    free_substr_list(ltr->next);
    free(ltr);
}
int match_letter(letter* ltr, char ch){  //checks if the letter has already appeared in substring
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
int max(substr* str){  //return the max length substring
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

    if(strlen(s)==1){
        return 1;
    }

    letter* ltr = (letter*)malloc(sizeof(letter));
    ltr->c = '\0';
    ltr->count=0;
    ltr->next = NULL;

    substr* word = (substr*)malloc(sizeof(substr));
    word->str = "";
    word->len=0;
    word->next = NULL;
    
    int substring_index;

    for(int i=0;s[i]!='\0';i++){
        if(letter_do_not_exist(ltr, s[i]))
            create_node_letter(ltr,s[i]);
    }

    int front,rear;
    front=rear=0;
    int match_letter_value;
    int once = 0;

    while(s[rear]!='\0'){
        match_letter_value=match_letter(ltr,s[rear]);
        if(match_letter_value){
            rear++;
            once=0;
        }
        else{
            int length_of_substr=rear-front;
            char* substring = (char*)malloc(length_of_substr*sizeof(char));
            substring_index=0;
            
            for(int i = front; i<rear; i++){
                substring[substring_index] = s[i];
                substring_index++;
            }
            
            create_node_string(word,substring,length_of_substr);
            
            reset_letter_count(ltr);
            match_letter_value=match_letter(ltr,s[rear]);
            front=rear;
            rear++;

            once = 1;
        }
    }
        if(!once){
            int length_of_substr=rear-front;
            char* substring = (char*)malloc(length_of_substr*sizeof(char));
            substring_index=0;
            
            for(int i = front; i<rear; i++){
                substring[substring_index] = s[i];
                substring_index++;
            }
            
            create_node_string(word,substring,length_of_substr);
        }

        int max_value=max(word);
        free_letter_list(ltr);
        free_substr_list(word);
        return max_value;
}