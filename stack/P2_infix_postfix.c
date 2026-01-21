#include<stdio.h>
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
int top = -1;
char st[20];
void push(char ch){
    st[++top] = ch;
}

char pop(){
    if(top == -1)
        return 0;
    char val = st[top];
    top--;
    return val;
}

char peek(){
    if(top == -1)
        return 0;
    return st[top];
}

char infixToPostfix(char* s){

int i =0,j=0;
char ans[20] = "";

while (s[i] != '\0' )
{
    if (s[i] >= 'a' && s[i] <= 'z' )
    {
        ans[j] += s[i];
        j++;
    }
    else if (s[i] == '(')
    {
       push(s[i]);
    }
    else if (s[i] == ')')
    {
        while (top != -1 && peek() != '(')
        {
            ans[j] += pop();
            j++;
        }
        pop();
    
    
}
else
{
    while (top != -1 && precedence(peek()) >= precedence(s[i]))
    {
        ans[j] += pop();
        j++;
    }
    push(s[i]);
}

i++;
}
while (top != -1)
{
    ans[j] += pop();
    j++;
}
ans[j] = '\0';
return ans;
}

int main(){
    char s[20];
    printf("Enter the infix expression: ");
    scanf("%s",s);
    char postfix = infixToPostfix(s);
    printf("Postfix expression: %s\n",postfix);
    return 0;
}