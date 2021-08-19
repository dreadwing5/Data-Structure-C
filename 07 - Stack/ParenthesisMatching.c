#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *A;
};
void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        //Push Element
        st->top++;
        st->A[st->top] = x;
    }
}
char pop(struct Stack *st)
{
    char x;
    if (st->top == -1)
    {
    }
    else
    {
        x = st->A[st->top--];
    }
    return x;
}
bool isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return true;
    }
    return false;
}
char stackTop(struct Stack st)
{
    if (isEmpty(st))
        return 0;
    return st.A[st.top];
}

bool isBalannce(char *exp)
{
    char x;
    bool flag = false;
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.A = (char *)malloc(st.size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        //Check for parenthesis
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&st, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            //Check if stack is empty
            if (isEmpty(st))
            {
                return false;
            }
            else
            {
                do
                {
                    x = pop(&st);
                    if (x == ')')
                    {
                        flag = exp[i] == x - 1 ? true : false;
                    }
                    else
                    {
                        flag = exp[i] == x - 2 ? true : false;
                    }

                } while (flag);
            }
        }
    }
    //Check if stack is empty
    return isEmpty(st) ? true : false;
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
    case '%':
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
    case '%':
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
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

char *infixToPost(char *infix)
{
    struct Stack st;
    st.size = (strlen(infix));
    st.A = (char *)malloc(st.size * sizeof(char));
    st.top = -1;
    int len = strlen(infix) + 1;
    char *postfix = (char *)malloc(len * sizeof(char));
    int i, j;
    i = j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            //Check for precedance then put it into postfix
            postfix[j++] = infix[i++];
        }
        else
        {

            if (outPre(infix[i]) > inPre(stackTop(st)))
            {
                push(&st, infix[i++]);
            }
            //check for in precedence
            else if (outPre(infix[i]) < inPre(stackTop(st)))
            {
                postfix[j++] = pop(&st);
            }
            else
            {
                pop(&st);
                i++;
            }
        }
    }
    while (!isEmpty(st))
    {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char infix[20];
    printf("Enter an Expression:");
    fgets(infix, sizeof(infix),stdin);
    char *postfix;
    postfix = infixToPost(infix);
    printf("The postfix expression is : %s", postfix);
    printf("\n");
}