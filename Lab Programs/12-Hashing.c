#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int HT[MAX], F[MAX], L;

void linearProbe(int k, int key)
{
    L = k % MAX;
    if (HT[L] == 0)
    {
        HT[L] = key;
    }
    else
    {
        linearProbe(k + 1, key);
    }
}
void display()
{
    for (size_t i = 0; i < MAX; i++)
    {
        printf("\nHT[ %zu ] ----------> %d", i, HT[i]);
    }
    printf("\n");
}

int main()
{
    FILE *fp;
    int i = 0;
    char buff[1000];
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("File could not be opened!!!\n");
        exit(0);
    }
    while (fscanf(fp, "%d", &F[i]) != EOF)
    {
        fscanf(fp, "%[^\n]s ", buff);
        i++;
    }
    printf("\n The Number of data in files are : %d", i);
    for (size_t i = 0; i < MAX; i++)
    {
        L = F[i] % MAX;
        if (HT[L] == 0)
        {
            HT[L] = F[i];
        }
        else
        {
            linearProbe(F[i] + 1, F[i]);
        }
    }
    display();
    fclose(fp);
    return 0;
}
