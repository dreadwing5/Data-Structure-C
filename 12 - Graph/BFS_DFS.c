#include <stdio.h>
#include "Queue.h"

//Breadth First Search

void BFS(int G[][7], int start, int n)
{
    int visited[7] = {0}; //Set intitial value to 0
    int i, u;
    i = start;
    printf("%d ", start); //Print the first value
    visited[i] = 1;
    enQueue(i);

    while (!isQueueEmpty())
    {
        u = deQueue();
        for (int j = 1; j < n; j++)
        {
            if (G[u][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enQueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (int i = 1; i < n; i++)
        {
            if (G[start][i] == 1 && visited[i] == 0)
            {
                DFS(G, i, n);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    printf("The BFS is : ");
    BFS(G, 1, 7);
    printf("\n");
    printf("The DFS is : ");
    DFS(G, 3, 7);
}