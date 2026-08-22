// C Program to Convert Infix Expression to Postfix

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define size 100

char infix[size];
char stack[size];
char postfix[size];

int top = -1;

// Push character into stack
void push(char ch)
{
    top++;
    stack[top] = ch;
    stack[top + 1] = '\0';
}

// Pop character from stack
char pop()
{
    char ch;

    ch = stack[top];
    top--;

    stack[top + 1] = '\0';

    return ch;
}

int main()
{
    int i, j = 0;
    int step = 1;

    printf("\n==============================================");
    printf("\n       INFIX TO POSTFIX CONVERSION");
    printf("\n==============================================");

    printf("\n\nEnter Infix Expression : ");
    scanf("%s", infix);

    // Add brackets for easy conversion
    push('(');
    strcat(infix, ")");

    printf("\n\n----------------------------------------------");
    printf("\n Step\tSymbol\t\tStack\t\tPostfix");
    printf("\n----------------------------------------------");

    for (i = 0; i < strlen(infix); i++)
    {
        switch (infix[i])
        {
        // Opening bracket
        case '(':
            push(infix[i]);
            break;

        // Closing bracket
        case ')':

            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
                postfix[j] = '\0';
            }

            pop();
            break;

        // + and -
        case '+':
        case '-':

            while (stack[top] == '^' ||
                   stack[top] == '/' ||
                   stack[top] == '*' ||
                   stack[top] == '+' ||
                   stack[top] == '-')
            {
                postfix[j] = pop();
                j++;
                postfix[j] = '\0';
            }

            push(infix[i]);
            break;

        // * and /
        case '*':
        case '/':

            while (stack[top] == '^' ||
                   stack[top] == '*' ||
                   stack[top] == '/')
            {
                postfix[j] = pop();
                j++;
                postfix[j] = '\0';
            }

            push(infix[i]);
            break;

        // ^
        case '^':
            push(infix[i]);
            break;

        // Operand
        default:
            postfix[j] = infix[i];
            j++;
            postfix[j] = '\0';
        }

        printf("\n %2d\t  %c\t\t%-10s\t%s",
               step,
               infix[i],
               stack,
               postfix);

        step++;
    }

    printf("\n----------------------------------------------");

    printf("\n\n==============================================");
    printf("\n      POSTFIX EXPRESSION = %s", postfix);
    printf("\n==============================================");

    getch();

    return 0;
}