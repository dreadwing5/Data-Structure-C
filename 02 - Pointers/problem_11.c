#include <stdio.h>

void factorial(int n, int *f)
{
    *f = 1;
    for (int i = 1; i<=n; i++)
    {
        *f*=i;
    }
}

void main()
{

    char a[5] = {'a', 'b', 'c', 'd'};
    int n = 0, temp, result;
    int fact;
    factorial(n,&fact);
    printf("%d", fact);
}