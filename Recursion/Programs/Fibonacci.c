#include <stdio.h>

//Fibonacci using loop, are you sure you want to write using loop?

int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;

    if (n <= 1)
        return n;

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}
//Don't use this method , it's an example of ecessive recursion
//Time complexity is O(2^n)
//This method sucks!!!

int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

//Using Memoization method to reduce time
//Holy shit, i can't beleive it reduces the time form O(2^n) to O(n)
//Store all the function call in array


int F[10]; // Array to store the function call
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    int i;
    for (i = 0; i < 10; i++)
        F[i] = -1;

    printf("%d \n", mfib(5));
    return 0;
}