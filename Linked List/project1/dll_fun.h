#ifndef DLL_FUN_H //checks if sLL_FUN_H is NOT defined
#define DLL_FUN_H // define it

#include<stdlib.h>
#include<stdio.h>
struct d_Node{
    struct d_Node *prev;
    int data;
    struct d_Node *next;

};

struct d_Node *head = NULL;
struct  d_Node *tail = NULL;




struct d_Node{
    struct d_Node *prev;
    int data;
    struct d_Node *next;

};

struct d_Node *head = NULL;
struct  d_Node *tail = NULL;




void d_create() {
    struct d_Node *temp;
    int x;

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
        scanf("%d", &x);

    } while (x == 1);
}

void d_display() {
    struct d_Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
   

    while (temp != NULL) {
        printf("prev : %u data: %d next : %u \n",temp->prev, temp->data , temp->next);
        temp = temp->next;
    }

 
}

#endif