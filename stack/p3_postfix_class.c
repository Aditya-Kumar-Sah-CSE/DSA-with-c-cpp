#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX 50
char stack[MAX];
int top = -1;
void push(char x){
stack[++top]=x;
}
char pop(){
    return stack[top--];
}

void printStack() {
    int i;
    printf("Stack: ");
    if (top == -1) {
        printf("Empty");
    } else {
        for (i = 0; i <= top; i++)
            printf("%c ", stack[i]);
    }
    printf("\n");
}
int precedence(char ch){
    if(ch== '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch=='/'){
        return 2;
    }
    if(ch == '^'){
        return 3;
    }
        return 0;
}
int main(){
char Q[50] , P[50];
printf("Enter the infix expression : \n");
scanf("%s",Q);
char c = '(';
push(c);
printf("\n");
int k =0;
while(Q[k] != '\0')
    k++;
    Q[k] = ')';
    Q[k+1] = '\0';
printf("add ) to Q : %s\n",Q);
 int  i=0;
 int j = 0;
for(int i = 0 ; i<=k;i++)
{
   
    if(Q[i] >= 'a' && Q[i]<= 'z'){
        P[j] = Q[i];
        printf("%c\n",P[j]);
        j++;
    }
    else if(Q[i] == '('){
        push(Q[i]);
    }
    else if(Q[i] == ')'){
      
        while(top!= -1 && stack[top] != '('){
             P[j] = pop();
             printf("%c\n",P[j]);
        j++;
        }
        pop();
    }
    else{
        while(top!=-1 && precedence(stack[top]) >=precedence(Q[i])){
            P[j]=pop();
            printf("%c\n",P[j]);
            j++;
        }
    push(Q[i]);
    printStack();
    }
}
P[j]='\0';
printf("\n");
printf("%s\n",P);
    return 0;
}