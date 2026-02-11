#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, priority;
    struct node *next;
};

struct node *head = NULL;

void enqueue(int data, int p) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->priority = p;
    temp->next = NULL;

    if (head == NULL || p < head->priority) {
        temp->next = head;
        head = temp;
    } else {
        struct node *cur = head;
        while (cur->next && cur->next->priority <= p)
            cur = cur->next;
        temp->next = cur->next;
        cur->next = temp;
    }
}

void dequeue() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }
    struct node *temp = head;
    printf("Deleted: %d\n", temp->data);
    head = head->next;
    free(temp);
}

void display() {
    struct node *temp = head;
    while (temp) {
        printf("%d(p=%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int v ;
    int data , p;
do{
    printf("\nEnter 1 for enqueue , 2 for deque , 3 for display and 0 for exit !! \n");

scanf("%d",&v);
switch(v){
    case 1 :
    
    printf("Enter value of queue \n");
    scanf("%d",&data);

    printf("Enter priority \n");
    scanf("%d",&p);
    enqueue(data,p);
    break;

    case 2 :
    dequeue();
    break;

    case 3:
    display();
    break;

    

}
}while (v);
}
