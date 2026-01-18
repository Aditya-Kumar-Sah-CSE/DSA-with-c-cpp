#include<stdio.h>
int main(){
int n;
printf("Enter no of process : ");
scanf("%d",&n);;
int at[n];
printf("Enter program Arrival time : ");
for(int i=0;i<n;i++){
    int a ;
    scanf("%d",&a);
    at[i] = a;
}
// for(int i=0;i<n;i++){
//     printf("%d",at[i]);
// }
int bt[n],sum = 0;
printf("Enter program Burst time : ");
for(int i=0;i<n;i++){
    int a ;
    scanf("%d",&a);
    sum+=a;
    bt[i] = a;
}

// gantt chat
int gt[n+1], data =0;
gt[0]=0+at[0];
for (int i = 0; i<n ; i++)
{
if (at[i]<=gt[i+1])
{
    /* code */
    data+=bt[i];    
    gt[i+1]=data;
   
}

    



}

// for(int i=0;i<=n;i++){
//     printf("%d ",gt[i]);
// }


int ct[n];

for (int i = 0; i < n; i++)
{
    ct[i] = gt[i+1];

}

int tat[n];

for (int i = 0; i < n; i++)
{
    tat[i] = ct[i] - at[i];

}

int wt[n];

for (int i = 0; i < n; i++)
{
    wt[i] = tat[i] - bt[i];

}

int rt[n];

for (int i = 0; i < n; i++)
{
    wt[i] = gt[i] - at[i];

}
printf("\n");
for(int i=0;i<n;i++){
    printf("ct for program %d : %d \n",i+1,ct[i]);
}

printf("\n");
for(int i=0;i<n;i++){
    printf("tat for program %d : %d \n",i+1,tat[i]);
}
printf("\n");
for(int i=0;i<n;i++){
    printf("wt for program %d : %d \n",i+1,wt[i]);
}

}