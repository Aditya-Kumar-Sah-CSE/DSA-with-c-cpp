#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
 struct Node *head = NULL;
 
void create(){
    struct Node *temp ,*ptr;
     int   x ,ch;
    do{
       
        temp = (struct Node *)malloc(sizeof(struct Node ));
        printf("\n Enter the data : ");
        scanf("%d",&x);

        temp->data = x;
        temp ->next = NULL;

       
        if(head == NULL){
            head = temp;
        }
            
           
         else{
                ptr = head ;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                 }
                    ptr ->next = temp;
               
                
            }


printf("Enter 1 if want more or 0 \n");
scanf("%d",&ch);

    }while(ch==1);
    
}


void insertAtBegin_void(){
    int x ;
struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node *));
    printf("\nEnter the new data and enter cls: ");
    scanf("%d ",&x);
    temp->data = x;
    temp->next=head;
    head = temp;
}

struct Node * insertAtBegin(){
    int x ;
    struct  Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node *));
    printf("\nEnter the new data and enter cls: ");
    scanf("%d ",&x);
    temp->data = x;
    temp->next=head;
}


void display(){
        struct Node *ptr = head;
    while(ptr !=NULL){
printf("data : %d  address : %u \n",ptr->data , ptr->next);
ptr=ptr->next;
    }
}





int main(){
    create();

printf("\nnow print it !\n");
   display();

   insertAtBegin_void();
   printf("\n now after print it !\n");
   display();

//    head = insertAtBegin();
//    printf("\n now after print it !\n");
//    display();

    return 0;
}


