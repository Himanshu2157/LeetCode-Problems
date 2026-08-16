#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* ptr=head;
    int* position = (int*)malloc(sizeof(int));
    *position = 1;

    while(ptr->next!=NULL){
        ptr=ptr->next;
        (*position)+=1;
    }

    ptr=head;
    if((*position)>100){
        free(position);
        free(ptr);
        return NULL;
    }
    
    int* middle = (int*)malloc(sizeof(int));
    *middle = (*position/2)+1;
    
    int *pointer = (int*)malloc(sizeof(int));
    *pointer=1;
    
    while((*pointer)!=(*middle)){
        ptr=ptr->next;
        (*pointer)++;
    }
    
    free(position);
    free(middle);
    free(pointer);
    return ptr;
}

/*Note: Remove main() and struct ListNode from code before Submission*/

int main(){
    int* middle;
    *middle = 100;
    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* n1 = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*) malloc (sizeof(struct ListNode));
    head->val = 10;
    n1->val = 20;
    n2->val = 30;
    n3->val = 40;
    n4->val = 50;

    head->next=n1;
    n1->next=n2; 
    n2->next=n3; 
    n3->next=n4; 
    n4->next=NULL; 
    struct ListNode* ptr = middleNode(head);
    printf("middle value= %d", ptr->val);

    return 0;
}