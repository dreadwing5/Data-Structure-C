#include <stdio.h>
#include <stdlib.h>
//Operation on Circular Linked List

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
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
    if (!P)
        return; //Check Null condition
    do
    {
        printf("%d ", P->data);
        P = P->next;
    } while (P != first);
}
void rDisplay(struct Node *P)
{
    static int flag = 0;
    if (P != first || flag == 0)
    {
        printf("%d ", P->data);
        flag = 1;
        rDisplay(P->next);
    }
    flag = 0;
}
int countNode(struct Node *P)
{
    int count = 0;
    do
    {
        P = P->next;
        count++;
    } while (P != first);
    return count;
}

void insertNode(struct Node *P, int x, int count, int index)
{
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
            t->data = x;
            //Check if the linked list is empty
            if (first == NULL)
            {
                first = t;
                first->next = first;
            }
            else
            {
                while (P->next != first)
                {
                    P = P->next;
                }
                P->next = t;
                t->next = first;
                first = t;
            }
        }
        else
        {
            t = (struct Node *)malloc(sizeof(struct Node *));
            t->data = x;
            for (int i = 0; i < index - 1; i++)
            {
                P = P->next;
            }
            t->next = P->next;
            P->next = t;
        }
    }
}
int deleteNode(struct Node *P, int index, int count)
{
    int x;
    if (index < 0 || index > count)
    {
        return -1;
    }
    if (index == 0)
    {
        x = P->data;
        while (P->next != first)
        {
            P = P->next;
        }
        if (P == first)
        {
            free(first);
            first = NULL;
        }
        else
        {
            P->next = first->next;
            free(first);
            first = P->next;
        }
        return x;
    }
    else
    {
        struct Node *q;
        q = first;
        for (int i = 0; i < index; i++)
        {
            q = P;
            P = P->next;
        }
        x = P->data;
        q->next = P->next;
        free(P);
        return x;
    }
}

int main()
{
    int A[] = {10};
    int n = sizeof(A) / sizeof(int);
    create(A, n);
    first->next = first;
    int count = countNode(first);
    /* insertNode(first, 60, count, 0);
printf("\n");
display(first); */
    printf("\n%d is deleted! ", deleteNode(first, 0, count - 1));
    display(first);
    return 0;
}