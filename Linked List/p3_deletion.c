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

// case 1 delete from first node

struct Node * deleteFirst(struct Node * head){
struct Node * ptr = head;
head = head -> next;
free(ptr);
return head;

}                                                
//case 2 delete a node at index 
struct Node * deleteAtIndex(struct Node * head,int index){
struct Node * p = head;
struct Node * q = head->next;
for (int i = 0; i < index - 1; i++){
    
}
{
    /* code */
}

head = head -> next;

return head;

}   
int main(){
 // 3 pointer banao 
    struct  Node * head;
    
    struct  Node * second;
    
    struct  Node * third;

    struct  Node * forth;
    
// Allocate memory for nodes in linked list in heap
     head = (struct Node *)malloc(sizeof(struct Node));
    
    
     second = (struct Node *)malloc(sizeof(struct Node));

     
     third = (struct Node *)malloc(sizeof(struct Node));

      forth = (struct Node *)malloc(sizeof(struct Node));
    // feed data
     head -> data = 7;
     head->next = second;

     
    second -> data = 22;
    second->next = third;

   third -> data = 2;
   third-> next = forth;

   forth -> data = 2;
   forth-> next = NULL;

   // call
   stNodeTr(head);



//    deletion 

// delete from first element from 
head = deleteFirst(head);
printf("deleting the first node \n");
stNodeTr(head);

//for deleting element of the linked list

head = deleteAtIndex(head,1);
printf("Linked list after deletion \n");
stNodeTr(head);

    return 0;
}