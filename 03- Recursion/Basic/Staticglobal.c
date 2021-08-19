#include <stdio.h>

int my_func(int n)
{
    static int x = 0;

    if (n > 0)
    {
        x++;
        return my_func(n - 1) + x;
    }
    return 0;
}
void main()
{

    int n = 5, result;
    result = my_func(n);
    printf("%d\t", result);
}