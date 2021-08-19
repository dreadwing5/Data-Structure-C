#include <stdio.h>
#include <stdlib.h>
int A[50][50], n, visited[20];

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
//Breadth First Search
void BFS(int i)
{
    int u;
    visited[i] = 1;
    enQueue(i);

    while (!isQueueEmpty())
    {
        u = deQueue();
        for (int j = 1; j <= n; j++)
        {
            if (A[u][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enQueue(j);
            }
        }
    }
}

void DFS(int start)
{
    static int flag = 0;

    if (visited[start] == 0)
    {
        if (flag == 1)
        {
            printf("%d ", start);
        }

        visited[start] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (A[start][i] == 1 && visited[i] == 0)
            {
                flag = 1;
                DFS(i);
            }
        }
    }
}

int main()
{
    int ch, start, i, j;
    printf("\nEnter the number of vertex:  ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    while (1)
    {
        printf("\n1.BFS\n2.DFS\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter The Starting Vertex : ");
            scanf("%d", &start);
            printf("\nThe nodes which are reachable from %d:\n", start);
            BFS(start);
            break;
        case 2:
            for (int i = 0; i <= n; i++)
            {
                visited[i] = 0;
            }
            printf("Enter The Starting Vertex : ");
            scanf("%d", &start);
            printf("\nThe nodes which are reachable from %d:\n", start);
            DFS(start);
            break;
        case 3:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}