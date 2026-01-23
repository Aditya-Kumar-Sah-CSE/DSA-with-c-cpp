#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX  20

int Stack[MAX];
int top=-1;

int pop(){
    return Stack[top--];
}

void push(int op){
    Stack[++top]= op;

}

int peek(){
    return Stack[top];
}




int main(){

    char P[20] ,res =0;

    scanf("%s",P);
    int i = 0;
    while (P[i] != '\0')
    {
        i++;
    }
    
    P[i] = ')';
    P[i+1] = '\0';
    printf("%s\n",P);
int l = i;
// printf("%d\n",l);
 
for (int i = 0; i < l; i++)

    {
        int num = P[i] - '0';
        printf("%d\n",num);
        if(num>0 && num< 10 ){
            push(num);
            // printf("%d\n ",peek());
        }
        else{
char operator = P[i];
int op2 = pop();
int op1 = pop();
printf("%c\n",operator);
 res =0 ;
switch(operator){
    case '+' :
    res = op1 + op2;
    break;
    case '-' :
    res = op1 - op2;
    break;
    case '*' :
    res = op1 * op2;
    break;
    case '/' :
    res = op1 / op2;
    break;
    case '^' :
    res = pow(op1 , op2);
    break;

}
push(res);
        }

    }
printf("res : %d \n",res);
     printf("peek %d ",peek());
    return 0;
}

