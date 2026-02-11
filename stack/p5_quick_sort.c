#include<stdio.h>
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quickSort(int a[] ,int low ,int high){
    int p_i;
    // index of pivot after partition
if(low<high){
p_i = partition(a,low,high);
quickSort(a,low,p_i - 1);//sort left 
quickSort(a,p_i + 1,high);//sort right
}
}
void printArray(int *a , int n){
    for (int i = 0; i < n; i++)
    {
         printf("%d ",a[i]);
    }
    printf("\n");
   
}

int main(){
int a[] ={3,5,2,11,9};
int n = 5;
printArray(a,n);
quickSort(a,0,n-1);
printArray(a,n);
    return 0;
}