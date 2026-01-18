#include<stdio.h>
#include<stdlib.h>
#define MAX 15;
int check_precedence(char ch){
    if(ch == '(' || ch == ')') return 1;
    else if(ch == '!' || ch == '~' || ch == '++' || ch == '--' ) return 2;
    else if (ch == '*' || ch == '/' || ch == '%') return 3;
    else if (ch == '+' || ch == "-") return 4;

    
    return 0;
}

char stack[15];
int top = -1;

char pop(){
    char ch = stack[top];
top--;
return ch;
}


void push(char ch){ 
    int cur_priority = check_precedence(ch);
    top++;
stack[0] ="(";
    int priority = 5;

    if (cur_priority<priority){
top++;
stack[top]=ch;
priority=cur_priority;

    }
   else {

        while (priority>cur_priority)
        {
            /* code */
        }
        
    }
    




    stack[top] = ch;
}

int main(){

    char s[12] = "2+3*5-6/8+14)";
    char res[14] ="";
    int j=0;
for (int i = 0; i < 11; i++)
{
    
    int num = (s[i]);
    if(num>=0 && num<10){
res[j]=num;
j++;
    }
    else{
        push(s[i]); 
    }
    
}




}