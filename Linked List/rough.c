#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};



int main(){

    struct Node * head;
    struct Node * second;

    head = (struct Node *)malloc(sizeof(struct Node ));
    second= (struct Node *)malloc(sizeof(struct Node ));
  
    head->data = 7;
    head->next = second;

    second->data = 22;
    second->next = NULL;

    return 0;
}
