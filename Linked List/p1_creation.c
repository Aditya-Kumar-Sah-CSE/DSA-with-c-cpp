#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node * next;
 
};

void stNodeTr(struct Node* ptr) 
{
    /* data */
    while(ptr != NULL){
           printf("Element : %d \n",ptr->data);
    ptr = ptr -> next;
    }
 
};



int main(){
 // 3 pointer banao 
    struct  Node * head;
    
    struct  Node * second;
    
    struct  Node * third;
    
// Allocate memory for nodes in linked list in heap
     head = (struct Node *)malloc(sizeof(struct Node));
    
    
     second = (struct Node *)malloc(sizeof(struct Node));

     
     third = (struct Node *)malloc(sizeof(struct Node));
    // feed data
     head -> data = 7;
     head->next = second;

     
    second -> data = 22;
    second->next = third;

   third -> data = 2;
   third-> next = NULL;

   // call
   stNodeTr(head);
    return 0;
}