/*Find the intersection of two linked list using stack*/

#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

struct Stack
{
    int size;
    int top;
    struct Node **S; //It's going to store the address that's why we are using double derefereincing
};
void createStack(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(size * sizeof(struct Node **));
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {

        st->top++;
        st->S[st->top] = x; //Storing The Address
    }
}
struct Node *pop(struct Stack *st)
{
    struct Node *x;
    if (st->top == -1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
void create(int A[], int n)
{
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create1(int A[], int n)
{
    struct Node *last, *t;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct Node *P)
{
    while (P)
    {
        printf("%d ", P->data);
        P = P->next;
    }
}
int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *stackTop(struct Stack st)
{
    if (!isEmpty(st))
    {
        return st.S[st.top];
    }

    return NULL;
}
void findIntsec(struct Node *P, struct Node *q)
{
    struct Stack st1, st2;
    struct Node *result;
    createStack(&st1, 100);
    createStack(&st2, 100);
    P = first;
    while (P)
    {

        P = P->next;
        push(&st1, P);
    }
    P = second;
    while (P)
    {

        P = P->next;
        push(&st2, P);
    }
    while (stackTop(st1) == stackTop(st2))
    {
        result = stackTop(st1);
        pop(&st1);
        pop(&st2);
    }
    printf("%d", result->data);
}
int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70};
    int B[] = {3, 6};
    int y = sizeof(B) / sizeof(int);
    int n = sizeof(A) / sizeof(int);
    create(A, n);
    create1(B, y);
    struct Node *t;
    t = second->next;
    t->next = first->next->next;
    findIntsec(first, second);
}