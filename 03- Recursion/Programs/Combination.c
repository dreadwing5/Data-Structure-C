#include <stdio.h>

int fact(int n)
{

    if (n == 0)
    {

        return 1;
    }
    return fact(n - 1) * n;
}

//Function for combination
//nCr = n! / ( r! * (n-r)! )
int com(int n, int r)
{

    int t1 = fact(n);
    int t2 = fact(r);
    int t3 = fact(n - r);
    int result = t1 / (t2 * t3);
    return result;
}

//Finding nCr using Recursion cuz why not?

int com1(int n, int r)
{

    if (r == 0 || n == r)
    {
        return 1;
    }
    return com1(n - 1, r - 1) + com1(n - 1, r); // Pascal Triangle
}

void main()
{

    int result = com1(4, 2);
    printf("%d ", result);
}