#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enQueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is Full!");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int deQueue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
    {
        printf("Queue is Full!");
    }
    else
    {
        t = front;
        x = t->data;
        front = t->next;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node *P;
    P = front;
    while (P)
    {
        printf("%d ", P->data);
        P = P->next;
    }
    printf("\n");
}

int main()
{
    enQueue(1);
    enQueue(2);
    Display();
    deQueue();
    Display();
}
