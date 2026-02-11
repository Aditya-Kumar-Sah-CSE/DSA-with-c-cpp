#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

int dequeue() {
    if (front == -1) {
        printf("Underflow\n");
        return -1;
    }
    int x = queue[front];
    printf("Deleted: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return x;
}

void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
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


// circular queue 
// enqueue
// check front == rear - overflow