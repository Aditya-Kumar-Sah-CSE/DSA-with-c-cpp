#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid,bt,pr,wt,tat;
    
    struct  process*next;

  
};
struct process*head = NULL;

void insert(int pid , int bt,int pr){
    struct process *temp = (struct process *)malloc(sizeof(struct process));
    temp->pid = pid;
    temp->bt =bt;
    temp->pr=pr;      
    temp->next = NULL;

    if(head == NULL || pr<head->pr){
        temp->next = head;
        head = temp;

    }else{
        struct process *ptr = head;
       while (ptr->next != NULL && ptr->next->pr <= pr)
       {
        ptr=ptr->next;
       }
       
       temp->next = ptr->next;
       ptr->next = temp;
        
    }
}

void cal(){
    struct process *temp = head;
    int time = 0;

    while(temp!= NULL){
        temp->wt = time;
        temp->tat = temp->wt + temp->bt;
        time+=temp->bt;
        temp = temp->next;
    }
}

void display(int n){
     struct process *temp = head;
    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               temp->pid, temp->bt, temp->pr,
               temp->wt, temp->tat);

        avg_wt += temp->wt;
        avg_tat += temp->tat;
        temp = temp->next;
}
 printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

}
int main(){
  int n, bt, pr;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nProcess %d", i);
        printf("\nBurst Time: ");
        scanf("%d", &bt);
        printf("Priority: ");
        scanf("%d", &pr);

        insert(i, bt, pr);
    }

    cal();
    display(n);


    return 0;
}