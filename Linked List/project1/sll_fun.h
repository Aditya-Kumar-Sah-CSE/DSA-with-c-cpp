#ifndef SLL_FUN_H //checks if sLL_FUN_H is NOT defined
#define SLL_FUN_H // define it

#include<stdlib.h>
#include<stdio.h>
//* creating a node of linked list as blue print 

struct Node {
    int data;
    struct Node * next;
};

//! create the first node pointer of struct node type - globally defined 

 struct Node * head = NULL;

// create a function to form new linked list 

 void create(){

    // take two pointer temp to insert new element at last node and ptr to traverse the existing linked list 

    struct Node *temp ,*ptr;
     int x ,ch;

    do{
       // temp store the memory address of dynamically   allocated memory using malloc that is type casted as struct node type 

        temp = (struct Node *)malloc(sizeof(struct Node ));

        printf("\n Enter the data : ");
        scanf("%d",&x);
        temp->data = x;

        // as the new node is inserted at last/end so it store NULL in next pointer 
        temp ->next = NULL;

       // for the 1st node if executed and head always pointing to 1st temp address

        if(head == NULL){
            head = temp;
        }

            // for 2nd or more node else will executed 
           
         else{
            // ptr is only for traversing the linked list , it always start with pointing the head pointer 
                ptr = head ;

                // while is only used to find the last node of the linked list , after which new node is attached ...

                while (ptr -> next != NULL)
                {
                    // the value of ptr always keep updating to next node address 
                    ptr = ptr -> next;
                 }

                 // make existing last node having NULL value  changed to address of new temp  
                    ptr ->next = temp;
               
                
            }


printf("Enter 1 if want more or 0 \n");
scanf("%d",&ch);

    }while(ch==1);
    
}

//* function for inserting 
//! case1 : inserting at begin 
//! case2 : inserting at end
//! case3 : inserting after a data y 
//! case4 : inserting before a data y 


//! case1 : inserting at begin 

void insertAtBegin(){
    int x ;
    struct  Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter the new data for begining : ");
    scanf("%d ",&x);
    // system("cls");
    temp->data = x;

    //! vv. imp. first we have to store the address of old head to temp -> next  

    temp->next=head;
    head = temp;
}
void insertAtBegin_void(){
    int x ;
    struct  Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter the new data for begining : ");
    scanf("%d ",&x);
    // system("cls");
    temp->data = x;

 

    temp->next=head;
   head= temp;

   
}

//! case2 : inserting at end
void insertAtEnd()
{
    int x;
    printf("Enter a new data for end node and enter cls ");
 
      struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;
    while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }

    ptr->next = temp;
    temp->next=NULL;
      scanf("%d",&x);
    temp->data = x;
  
    
};


//! case3 : inserting after a data y 

 
 void insertAfterY(){
    /* data */
    int x, y;
    struct Node * temp , *ptr ;
ptr=head;
   temp = (struct Node *)malloc(sizeof(struct Node));
   printf("\n Enter the new data \n");
    scanf("%d",&x);
    temp->data = x;
      printf("\nEnter the  data after which new node is inserted \n");
    scanf("%d",&y);
    while ((ptr->data != y))
    {
        ptr=ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    

};


//! case4 : inserting before a data y 


void insertBeforeY()
{
    /* data */
    int x, y;
    struct Node * temp , *ptr , *ptr1 ;
ptr=head;
   temp = (struct Node *)malloc(sizeof(struct Node));
   printf("\n Enter the new data \n");
    scanf("%d",&x);
    temp->data = x;
      printf("\nEnter the  data before which new node is inserted \n");
    scanf("%d",&y);
    while ((ptr->data != y))
    {
        ptr1=ptr;
        ptr=ptr->next;
    }
    temp->next = ptr1->next;
    ptr1->next = temp;
    

};

//* function to delete a node

//! case1 : delete the first node 

void deleteFirst()
{
    struct Node *ptr;
   ptr = head;
   head = head->next;
   ptr->next =NULL;
   free(ptr);
   ptr=NULL;



};

//! case2 : delete the last node 

void deleteLast()
{
    struct Node *ptr ,*ptr1 ;
    ptr=head;
    while (ptr->next != NULL)
    {
        /* code */
        ptr1=ptr;
        ptr= ptr->next;
    }
    ptr1->next = NULL;
    free(ptr);
    ptr = NULL;
    
 
    
};


//! case3 : delete after y 

void deleteAfterY()
{
    int x;
    printf("Enter value  after which u want to delete a node ");
    scanf("%d",&x);
    struct Node *ptr ,*ptr1 ;
    ptr=head;
    while (ptr->data != x)
    {
        /* code */
        ptr1=ptr;
        ptr= ptr->next;
    }
    ptr1->next = ptr->next;
    ptr->next=NULL;
    free(ptr);
    ptr = NULL;
    
};

//* function to display a linked list 

void display(){

    struct Node *ptr = head;

    //! ptr is only for traversing the linked list 

    while(ptr !=NULL){
    printf("data : %d  address : %u \n",ptr->data , ptr->next);
    ptr=ptr->next;
    }
}
#endif