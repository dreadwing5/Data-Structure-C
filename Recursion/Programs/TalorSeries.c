#include <stdio.h>

double Taylor(int x, int n)
{
    static double p = 1;
    static double f = 1;
    double r;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = Taylor(x, n - 1);
        p = p * x;
        f = f * n;
        return r + (p / f);
    }
}
//Taylor series using Horner's rule

double Taylor1(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    s = 1 + x * s / n;
    return Taylor1(x, n - 1);
}

void main()
{
    double result = Taylor1(1, 10); //10 means how precise your value is , higher the number more precise will be the value
    printf("%lf ", result);
}