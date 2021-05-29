#include <stdio.h>
#include <stdlib.h>

#ifndef Queue_h
#define Queue_h

//Queue Structure
struct Queue
{
    int data;
    struct Queue *next;
} *front = NULL, *rear = NULL;

void enQueue(int x)
{
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
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
            front = rear = t; //When the queue doesn't exist
        }
        else
        {
            rear->next = t; //Insert from rear
            rear = t;
        }
    }
}
int deQueue()
{
    int x;
    struct Queue *t;
    t = front;
    x = t->data;
    front = t->next;
    free(t);
    return x;
}

int isQueueEmpty()
{
    return front == NULL;
}
#endif