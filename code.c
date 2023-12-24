#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* detect_cycle_list(node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    node* slow = head->next;
    node* fast = head->next->next;
    while(fast!=NULL && slow!=NULL && fast!=slow){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast==NULL||fast->next==NULL){
        return NULL;
    }
    node* start = head;
    while(start!=slow){
        start = start->next;
        slow = slow->next;
    }
    node* current = start;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next=NULL;
    return start;
}
