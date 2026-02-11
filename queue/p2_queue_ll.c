#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;

    if (front == NULL) rear = NULL;
    free(temp);
}
void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }
struct Node *temp;
temp = front;
    while (temp->next == NULL ||temp->next >rare)
    {
        /* code */
    }
    
    printf("\n");
}

 int main(){
    int v ;
    int data;
do{
    printf("\nEnter 1 for enqueue , 2 for deque , 3 for display and 0 for exit !! \n");

scanf("%d",&v);
switch(v){
    case 1 :
    
    printf("Enter value of queue \n");
    scanf("%d",&data);
    enqueue(data);
    break;

    case 2 :
    dequeue();
    break;

    case 3:
    display();
    break;

    

}
}while (v);

return 0;


    

}