#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack overflow!\n");
    }
    if (top == NULL)
    {
        t->data = x;
        t->next = NULL;
        top = t;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop()
{
    int x = -1;
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
int peek(int pos)
{
    struct Node *P;
    P = top;
    for (int i = 1; P != NULL && i < pos - 1; i++)
    {
        P = P->next;
    }
    if (P)
    {
        return P->data;
    }
    else
    {
        return -1;
    }
}
bool isFull()
{
    struct Node *t;
    if (t)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool isEmpty()
{
    return top == NULL;
}
int stackTop()
{
    if (top)
    {
        return top->data;
    }
    return -1;
}

void display(struct Node *P)
{
    while (P)
    {
        printf("%d ", P->data);
        P = P->next;
    }
}

int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    display(top);
    printf("\n%d ", pop());
    printf("\n%d ", pop());
    printf("\n%d ", pop());
    printf("\n%d ", pop());
    /* printf("\n%d ", peek(1)); */
    printf("%s ", isFull() ? "true" : "false");
    printf("%s ", isEmpty() ? "true" : "false");
    printf("%d ", stackTop());
}