#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front; //For deletion
    int rear;  //For insertion
    int *Q;    //Pointer to an array
};

//Insert Elements
void enQueue(struct Queue *q, int x)
{
    //Check if queue is full
    if (q->rear == q->size - 1)
    {
        printf("Queue Overflow!");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x; //Insert element and move rear
    }
}
void cirEnQueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue Is Full!");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
int cirDeQueue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is Empty!");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int deQueue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue Underflow!");
    }
    else
    {
        x = q->Q[q->front];
        q->front++;
    }
    return x;
}

void display(struct Queue q)
{
    while (q.front != q.rear)
    {

        q.front = (q.front + 1) % q.size;
        printf("%d ", q.Q[q.front]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    printf("Enter The Size Of Queue : ");
    scanf("%d", &q.size);
    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;
    cirEnQueue(&q, 1);
    cirEnQueue(&q, 2);
    cirEnQueue(&q, 3);
    cirEnQueue(&q, 4);
    display(q);
}