#include<stdio.h>
#include<stdlib.h>
#define MAX   15;
struct stack
{
   int size;
   int top;
   int *arr;

};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){

// struct stack s;

// s.size=MAX;
// s.top = -1;
// s.arr=(int *)malloc(s.size * sizeof(int));

// take a stack pointer 

struct stack *s;

s->size=MAX;
s->top = -1;
s->arr=(int *)malloc(s->size * sizeof(int));

if(isEmpty(s)){
    printf("the stack is empty !");
}
    return 0;
}