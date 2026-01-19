#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

/* push into stack */
void push(char x) {
    stack[++top] = x;
}

/* pop from stack */
char pop() {
    return stack[top--];
}

/* return priority */
int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

/* print stack status */
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

int main() {
    char infix[50], postfix[50];
    int i, k = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        /* if operand */
        if (isalnum(ch)) {
            postfix[k++] = ch;
            printf("Read operand %c → add to postfix\n", ch);
            // printStack();
        }

        /* if '(' */
        else if (ch == '(') {
            push(ch);
            printf("Read '(' → push to stack\n");
            // printStack();
        }

        /* if ')' */
        else if (ch == ')') {
            printf("Read ')' → pop till '('\n");
            while (stack[top] != '(') {
                postfix[k++] = pop();
                printStack();
            }
            pop(); // remove '('
            // printStack();
        }

        /* if operator */
        else {
            printf("Read operator %c\n", ch);
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                postfix[k++] = pop();
                printStack();
            }
            push(ch);
            printStack();
        }
    }

    /* pop remaining operators */
    while (top != -1) {
        postfix[k++] = pop();
        printStack();
    }

    postfix[k] = '\0';

    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}