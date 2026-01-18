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

struct Node * insertAtFirst(struct Node *head ,  int data)
{
  struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr -> next = head;
    ptr -> data = data;
    return ptr;
  
};

struct Node * insertAtIndex(struct Node *head , int data , int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0 ;
    while (i != index -1)
    {
        /* code */

        p = p ->next;
         i++;
    }
    ptr->data = data;
    ptr -> next = p->next;
    p->next = ptr;

    return head;

  
}


struct Node * insertAtEnd(struct Node *head ,  int data)
{
  struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr -> data = data;
    struct Node * p = head;

    while(p->next != NULL){
        p=p->next;

    }
    p->next = ptr;
    ptr->next = NULL;


    return head;
  
};
 
struct Node * insertAfterNode(struct Node *head , struct Node *prevNode, int data)
{
  struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

ptr -> data = data;

ptr-> next = prevNode ->next;
prevNode -> next = ptr;


    return head;
  
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
stNodeTr(head);
printf(" \n");
head = insertAtFirst(head,100);

   // call
   stNodeTr(head);

   // insert at index
   printf(" insert at index\n");
   insertAtIndex(head,20,2);
    stNodeTr(head);

    // insert at end 
insertAtEnd(head,111);
   printf(" insert at end\n");
  
    stNodeTr(head);

    // insert after a node 
    insertAfterNode(head,second,700);
   printf(" insert at end\n");
  
    stNodeTr(head);
    return 0;
}