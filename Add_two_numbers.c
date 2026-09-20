#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void traversal(struct ListNode* ptr){
    while(ptr!=NULL){
        printf("%d", ptr->val);
        ptr=ptr->next;
    }
}

void create_node(struct ListNode* head, int value){
    if(head==NULL){
        // head->next=NULL;
        // head->val=value;
        return;
    }
    while(head->next!=NULL){
        head=head->next;
    }
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=ptr;
    ptr->next=NULL;
    ptr->val=value;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int numb1,numb2,sum,val_to_insert;
    struct ListNode* new_number = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_number->next=NULL;
    if(l1==NULL && l2!=NULL){
        numb1=0;
        numb2 = l2->val;
    }
    else if(l2==NULL && l1!=NULL){
        numb2=0;
        numb1 = l1->val;
    }
    else if(l2==NULL && l1==NULL)
        numb1=numb2=0;
    else{
        numb1 = l1->val;
        numb2 = l2->val;
    }
    sum = numb1+numb2+carry;
    val_to_insert = sum%10;
    carry = sum/10;
    l1=l1->next;
    l2=l2->next;
    new_number->val=val_to_insert;
    while(l1!=NULL && l2!=NULL){
        if(l1==NULL && l2!=NULL){
            numb1=0;
            numb2 = l2->val;
        }
        else if(l2==NULL && l1!=NULL){
            numb2=0;
            numb1 = l1->val;
        }
        else if(l2==NULL && l1==NULL)
            numb1=numb2=0;
        else{
            numb1 = l1->val;
            numb2 = l2->val;
        }
        sum = numb1+numb2+carry;
        val_to_insert = sum%10;
        carry = sum/10;
        l1=l1->next;
        l2=l2->next;
        create_node(new_number,val_to_insert);
    }
    if(carry)
        create_node(new_number,carry);

    return new_number;
}

int main(){

    struct ListNode *head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));

    head1->val = 2;
    head1->next = node2;

    node2->val = 4;
    node2->next = node3;

    node3->val = 3;
    node3->next = NULL;


    // Head 2: 5 -> 6 -> 4
    struct ListNode *head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    head2->val = 5;
    head2->next = node5;
    
    node5->val = 6;
    node5->next = node6;
    
    node6->val = 4;
    node6->next = NULL;
    
    struct ListNode* number;
    number = addTwoNumbers(head1, head2);

    traversal(number);

    return 0;
}