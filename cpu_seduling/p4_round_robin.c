#include<stdio.h>
int main(){


printf("Enter num of process : \n");
int p;
scanf("%d",&p);
int bt[p],rt[p],wt[p],tat[p];
printf("Enter bust time : \n");

for(int i= 0; i<p;i++){
    int v;

scanf("%d",&v);
bt[i]= v;
rt[i] = v;

}int tq;
printf("Enter Time Quantum  : \n");

scanf("%d",&tq);
  int time = 0, done;
    
    do {
        done = 1;

        for (int i = 0; i < p; i++) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } 
                // rem time < tq
                else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }

    } while (!done);

    // Turnaround time
    for (int i = 0; i < p; i++) {
        tat[i] = bt[i] + wt[i];
    }

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / p);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / p);

    return 0;


}