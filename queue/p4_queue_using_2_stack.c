#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int x) {
    s1[++top1] = x;
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Underflow\n");
        return;
    }

    if (top2 == -1)
        while (top1 != -1)
            s2[++top2] = s1[top1--];

    printf("Deleted: %d\n", s2[top2--]);
}

void display() {
    for (int i = 0; i <= top2; i++)
        printf("%d ", s2[i]);
    for (int i = top1; i >= 0; i--)
        printf("%d ", s1[i]);
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
}
