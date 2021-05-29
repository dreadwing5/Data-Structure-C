#include <stdio.h>
#include <stdlib.h>

void main()
{

    int *p, *q;
    p = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
    }
    printf("\n%u ",p);//Address of P
    q = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        q[i]=p[i];//Copy the content of p to q
    }
    printf("\n%u ",q);//Address of q
    free(p);
    p=q;//p is now pointing to the first element of q
    q = NULL; //q is pointing to null

    //Print increased p
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d ", p[i]);
    }
    printf("\n%u ", p);
}