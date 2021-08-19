#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i = 0;
    struct Node *last, *t;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[i];
    head->prev = NULL;
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        last->next = t;
        t->next = NULL;
        last = t;
    }
}

void insertNode(struct Node *P, int index, int x)
{
    struct Node *t;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
    }
    else
    {
        struct Node *q;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        for (int i = 0; i < index; i++)
        {
            q = P;
            P = P->next;
        }
        if (P == head)
        {
            q->next = t;
            t->prev = q;
            t->next = head;
            head->prev = t;
        }
        q->next = t;
        t->prev = q;
        t->next = P;
        P->prev = t;
    }
}
int deleteNode(struct Node *P, int index)
{
    int x = -1;
    if (index == 0)
    {
        x = head->data;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        return x;
    }
    else
    {
        struct Node *q;
        for (int i = 0; i < index; i++)
        {
            q = P;
            P = P->next;
        }
        if (P == head)
        {
            q->prev->next = head;
            head->prev = q->prev;
            x = q->data;
            free(q);
        }
        else
        {
            x = P->data;
            q->next = P->next;
            P->next->prev = q;
            free(P);
        }
    }
    return x;
}
void display(struct Node *P)
{
    if (!P)
        return; //Check Null condition
    do
    {
        printf("%d ", P->data);
        P = P->next;
    } while (P != head);
}

int main()
{
    struct Node *t;
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(int);
    create(A, n);
    t = head->next->next->next->next;
    t->next = head;
    head->prev = t;
    deleteNode(head, 4);
    display(head);
}
