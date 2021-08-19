//Convert Infix TO Postfix using stack linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;

} *top = NULL;

void push(int op)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {
        if (top == NULL)
        {
            t->data = op;
            t->next = NULL;
            top = t;
        }
        else
        {
            t->data = op;
            t->next = top;
            top = t;
        }
    }
}

int pop()
{
    int x;
    if (top == NULL)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        struct Node *t;
        x = top->data;
        t = top->next;
        free(top);
        top = t;
    }
    return x;
}
int isEmpty()
{
    return top == NULL;
}
int stackTop()
{
    if (top)
    {
        return top->data;
    }
    return 0;
}
int outPre(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 7;
    case ')':
        return 0;
    default:
        return 0;
    }
}
int inPre(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    default:
        return 0;
    }
}
int isOperand(char ch)
{
    //Check if expression is operand or operator
    return ((ch >= '0' && ch <= '9'));
}
char *infixToPost(char *infix)
{

    int len = strlen(infix) + 1;
    char *postfix = (char *)malloc(len * sizeof(char));
    int i, j;
    i = j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {

            //Check for out precedence
            if (outPre(infix[i]) > inPre(stackTop()))
            {
                push(infix[i++]);
            }
            //check for in precedence
            else if (outPre(infix[i]) < inPre(stackTop()))
            {
                postfix[j++] = pop();
            }
            else
            {
                pop();
                i++;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

double postfixEva(char *postfix)
{
    int i;
    double x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {

        if (isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            case '^':
                r = pow(x1, x2);
                break;

            default:
                break;
            }
            push(r);
        }
    }
    return r;
}

int main()
{
    char *postfix = "12+3^4/5";
    printf("Result is %lf", postfixEva(postfix));
    printf("\n");
}
