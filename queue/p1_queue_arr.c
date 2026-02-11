#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("queue is full \n");
        return;
    }

    if (front == -1) front = 0;
    queue[++rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("queue is empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
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