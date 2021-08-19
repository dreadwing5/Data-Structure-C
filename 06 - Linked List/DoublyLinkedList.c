#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *P)
{
    while (P != NULL)
    {
        printf("%d ", P->data);
        P = P->next;
    }
}
int Length(struct Node *P)
{
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

void insertNode(struct Node *P, int x, int index, int count)
{
    //Check for valid indexition
    if (index < 0 || index > count)
    {
        return;
    }
    else
    {
        struct Node *t;
        if (index == 0)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            //Check For NULL condition
            if (first == NULL)
            {
                first = t;
                first->data = x;
                first->next = NULL;
                first->prev = NULL;
            }
            else
            {
                t->data = x;
                t->next = first;
                t->prev = NULL;
                first->prev = t;
                first = t;
            }
        }
        //Inserting ELement at any index
        else
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            struct Node *q;
            q = first;
            int i = 0;
            t->data = x;
            while (i < index)
            {
                q = P;
                P = P->next;
                i++;
            }
            if (!P)
            {
                t->prev = q;
                t->next = NULL;
                q->next = t;
            }
            else
            {
                t->prev = P->prev;
                t->next = q->next;
                q->next = t;
                P->prev = t;
            }
        }
    }
}
int deleteNode(struct Node *P, int index, int count)
{
    if (index < 0 || index > count)
    {
        return 0;
    }
    else
    {
        int x = 0;
        if (index == 0)
        {
            x = first->data;
            P = first->next;
            P->prev = NULL;
            free(first);
            first = P;
            return x;
        }
        else
        {
            struct Node *q;
            q = first;
            int i = 0;

            while (i < index)
            {
                q = P;
                P = P->next;
                i++;
            }
            x = P->data;
            if (!P->next)
            {
                q->next = NULL;
                free(P);
                return x;
            }
            else
            {
                q->next = P->next;
                P->next->prev = P->prev;
                free(P);
                return x;
            }
        }
    }
}
void reverseElement(struct Node *P)
{
    struct Node *temp;
    while (P)
    {
        temp = P->next;
        P->next = P->prev;
        P->prev = temp;
        P = P->prev;
        if (P!= NULL && P->next == NULL)
        {
            first = P;
        }
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(int);
    create(A, n);
    int count = Length(first);
    reverseElement(first);
    Display(first);
}
