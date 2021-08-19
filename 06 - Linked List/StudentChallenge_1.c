//Find the middle node of a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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

void display(struct Node *P)
{
    while (P)
    {
        printf("%d ", P->data);
        P = P->next;
    }
}
int findMid(struct Node *P)
{
    struct Node *q;
    q = first;
    while (P)
    {
        P = P->next;
        if (P)
        {
            P = P->next;
        }
        if (P)
        {
            q = q->next;
        }
    }
    return q->data;
}

int findLoop(struct Node *first)
{
    struct Node *p, *q;
    q = first->next->next;
    p = q->next->next;
    p->next = q;
    struct Node *fast_ptr, *slow_ptr;
    fast_ptr = slow_ptr = first;
    while (fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (fast_ptr == slow_ptr)
            return 1;
    }
    return 0;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    int n = sizeof(A) / sizeof(int);
    create(A, n);
    display(first);
    printf("\n%d \n", findLoop(first));
}