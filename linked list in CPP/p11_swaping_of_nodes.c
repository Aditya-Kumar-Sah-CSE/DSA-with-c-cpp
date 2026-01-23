#include<stdio.h>
#include<stdlib.h>
#include "sll_fun.h"



struct Node *swap(struct Node *head){

if(head == NULL || head->next == NULL)
return head;

struct Node *temp = head->next;

head->next = swap(head->next->next);
temp->next = head;
return temp;
}

int main(){
    create();

    printf("Linked list before swapping nodes:\n");

    display();
swap(head);
printf("Linked list after swapping nodes:\n");
display();
    return 0;
}