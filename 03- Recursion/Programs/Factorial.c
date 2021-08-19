#include <stdio.h>

int Fact(int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return Fact(n - 1) * n;
    }
}

void main()
{

    int a = 5;
    int result = Fact(a);
    printf("%d ", result);
}