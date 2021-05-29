//Evaluation of Postfix Expression

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int isOperand(char ch)
{
    //Check if expression is operand or operator
    return ((ch >= '0' && ch <= '9'));
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