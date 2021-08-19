#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int F[MAX], HT[MAX], L;

void linear_probe(int k, int key)
{
    L = k % MAX;
    if (HT[L] == 0)
        HT[L] = key;
    else
        linear_probe(k + 1, key);
}

void display()
{
    int i;
    printf("\nHash Table:");
    for (i = 0; i < MAX; i++)
    {
        printf("\nHT [ %d ] ------> %d", i, HT[i]);
    }
}

int main()
{
    FILE *fp;
    int i;
    char buff[1000];
    fp = fopen("data.txt", "r");
    i = 0;
    while (fscanf(fp, "%d", &F[i]) != EOF)
    {
        fscanf(fp, "%[^\n]s ", buff);
        i++;
    }
    printf("\nThe number of records in the File are: %d", i);
    for (i = 0; i < MAX; i++)
    {
        L = F[i] % MAX;
        if (HT[L] == 0)
            HT[L] = F[i];
        else
            linear_probe(F[i] + 1, F[i]);
    }
    display();
    return (0);
}