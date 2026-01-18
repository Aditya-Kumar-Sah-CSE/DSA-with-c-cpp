#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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





int main(){

d_create();
d_display();
// max_min();
// palindrome();




return 0;
}