#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //Self Refrential Structure
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
void Display(struct Node *P)
{
    while (P != NULL)
    {
        printf("%d ", P->data);
        P = P->next;
    }
}

struct Node *lSearch(struct Node *P, int key)
{
    struct Node *q;
    while (P != NULL)
    {
        if (key == P->data)
        {
            q->next = P->next;
            P->next = first;
            first = P;
            return P;
        }
        q = P;
        P = P->next;
    }
    return NULL;
}

int main()
{
    int A[] = {3, 5, 7, 8, 11};
    int n = sizeof(A) / sizeof(int);
    create(A, n);
    struct Node *temp = lSearch(first, 5);
    if (temp != NULL)
    {
        printf("Key Found %d\n", temp->data);
    }
    else
    {
        printf("Key Not Found!\n");
    }
    Display(first);
}
