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

    char P[20] ;

    scanf("%s",P);
    int i = 0;
    // while (P[i] != '\0')
    // {
    //     i++;
    // }
    
    // P[i] = ')';
    // P[i+1] = '\0';
    printf("%s\n",P);
 i = 0;
// printf("%d\n",l);
 while(P[i] != '\0')
    {
 // Skip spaces
        if (P[i] == ' ') {
            i++;
            continue;
        }


        int num = P[i] - '0';
        printf("%d\n",num);
        if(num>=0 && num< 10 ){
            int num = 0;

            // Read full number
            while ((P[i] - '0' >= 0 && P[i] <10 )) {
                num = num * 10 + (P[i] - '0');
                i++;
            }
            push(num);
        }
        else{
char operator = P[i];
int op2 = pop();
int op1 = pop();

int res =0 ;
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

i++;
    }
     printf("%d ",peek());





    return 0;
}

