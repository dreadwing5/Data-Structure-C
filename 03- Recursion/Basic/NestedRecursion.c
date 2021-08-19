#include <stdio.h>

int my_func(int n)
{

    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return my_func(my_func(n + 11));
    }
}

void main()
{
    int result = my_func(30); //This function will always return 91 no matter what value you pass
    printf("result = %d ", result);
}