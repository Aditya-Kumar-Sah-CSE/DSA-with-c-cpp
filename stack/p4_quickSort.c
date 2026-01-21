#include<stdio.h>
  int low= 0,high =n-1,pivot =0,left =0,right = n;

int pivot_fix(int arr[20] , int n){
  




    while (left <= right && arr[pivot] <= arr[right])
    {
        right--;
    }
    int temp = arr[pivot];
    arr[right] = arr[pivot];
    arr[pivot] = temp;

    pivot = right;
    left++;
    while(left<=right && arr[pivot]>arr[left])
left++;

temp = arr[pivot];
arr[left] = arr[pivot];
arr[pivot] = temp;

left++;


}