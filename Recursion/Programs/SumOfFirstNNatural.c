#include <stdio.h>
int sum = 0;
int SumOfN(int n)
{
    
    if (n != 0)
    {
        sum =  SumOfN(n - 1)+n;
    }
    return sum;
}

void main()
{

    int result;
    result = SumOfN(5);
    printf("%d ", result);
}