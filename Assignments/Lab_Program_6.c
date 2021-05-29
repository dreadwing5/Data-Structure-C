#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front; //For deletion
    int rear;  //For insertion
    int *Q;    //Pointer to an array
};

void cirEnQueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue Is Full!\n");
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
        printf("Queue is Empty!\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display()
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
    int ch, ele, size;
    printf("Enter The Size Of Queue : ");
    scanf("%d", &size);
    q.size = size + 1;
    q.front = q.rear = 0;
    q.Q = (int *)malloc(q.size * sizeof(int));
    do
    {
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter The Element To Be Inserted : ");
            scanf("%d", &ele);
            cirEnQueue(&q, ele);
            break;

        case 2:
            cirDeQueue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(1);
            break;
            //Exit....
        }
    } while (ch != 4);
}