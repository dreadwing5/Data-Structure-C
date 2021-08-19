#include <stdio.h>

void my_func(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        my_func(n-1);
        my_func(n-1);
    }
}
void main()
{
    int a = 3;
    my_func(3);
}