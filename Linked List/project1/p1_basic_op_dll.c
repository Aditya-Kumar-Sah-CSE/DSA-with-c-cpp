#include<stdio.h>
#include<stdlib.h>

struct d_Node{
    struct d_Node *prev;
    int data;
    struct d_Node *next;

};

struct d_Node *head = NULL;
struct  d_Node *tail = NULL;




void d_create() {
    struct d_Node *temp;
    int choice;
   
    do {
        temp = (struct d_Node*)malloc(sizeof(struct d_Node));

        printf("Enter data: ");
        scanf("%d", &temp->data);

        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        printf("Enter 1 to add more d_nodes, 0 to exit: ");
        scanf("%d", &choice);

    } while (choice == 1);
}

void d_display() {
    struct d_Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    // printf("NULL <-> ");

    while (temp != NULL) {
        printf("prev : %u data: %d next : %u \n",temp->prev, temp->data , temp->next);
        temp = temp->next;
    }

    // printf("NULL\n");
}



// delete first d_node
void d_deleteFirstNode(){
    struct d_Node *temp=head;

    head=head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
}

void d_deleteFromLast(){
    struct d_Node *temp=tail;
    tail = tail->prev;
    tail->next=NULL;
    temp->prev = NULL;
    free(temp);
}
void d_deleteMidValue(){
    struct d_Node * pre2 ,*pre1,*temp = head;
int x;
    printf("Enter a value to delete ");
    scanf("%d",&x);
    while(temp->data != x){
        pre2=temp;
        temp=temp->next;
    }
pre1=temp->next;
pre1->prev  = pre2->next;
pre2->next=temp->next;
temp->prev=NULL;
temp->next =NULL; 
free(temp);
}

void d_insertAtHead(){
    struct  d_Node *temp = (struct d_Node*)malloc(sizeof(struct d_Node));
    
        /* data */
        int x;
        printf("Enter new value to Head : ");
        scanf("%d",&x);
        temp->data = x;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head=temp;
    
    
}
void d_insertAtEnd(){
    struct  d_Node *temp = (struct d_Node*)malloc(sizeof(struct d_Node));
    
        /* data */
        int x;
        printf("Enter new value to End : ");
        scanf("%d",&x);
        temp->data = x;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail= temp;
        
    
    
}

void d_insertBeforeY(){
    struct  d_Node *temp = (struct d_Node*)malloc(sizeof(struct d_Node));
    struct d_Node *last , *first ;
    first = head;
        int x,y;
        printf("Enter new value  : ");
        scanf("%d",&x);
         printf("Enter value need to search : ");
        scanf("%d",&y);
        while(first->data != y){
            last = first;
            first=first->next;
        }

        temp->data = x;
     last->next = temp;
     temp->prev=last;
     temp->next=first;
     first->prev = temp;
        
    
    
}

void d_insertAfterY(){
    struct  d_Node *temp = (struct d_Node*)malloc(sizeof(struct d_Node));
    struct d_Node *s_fast , *first ;
    first = head;

        int x,y;
        printf("Enter new value  : ");
        scanf("%d",&x);
         printf("Enter value need to search : ");
        scanf("%d",&y);
        while(first->data != y){
            
            first=first->next;
           
        }
s_fast = first-> next;
        temp->data = x;
     s_fast -> prev = temp;
     temp->next=s_fast;
     first->next=temp;
     temp->prev = first;
        
    
    
}


int main(){

d_create();
d_display();
// printf("\n delete from first \n");
// d_deleteFirstNode();

// d_display();
// d_deleteFromLast();
// printf("\n delete from last \n");

// d_display();
// printf("\n delete mid value  \n");
// d_deleteMidValue();
// d_display();

// printf("\n insert at head   \n");
//  d_insertAtHead();
// d_display();

// printf("\n insert at tail   \n");
// d_insertAtEnd();
// d_display();
 
// printf("\n insert at middle   \n");
// d_insertBeforeY();
// d_display();
printf("\n insert at middle   \n");
d_insertAfterY();
d_display();



return 0;
}