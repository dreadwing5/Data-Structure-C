#include <stdio.h>

int Pow(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p % 2 == 0)
    {

        return Pow(n * n, p / 2); // If power is even
    }
    return n * Pow(n * n, (p - 1) / 2); //Power is odd , This algorithm shortens the no. of multiplication
}
void main()
{
    int result = Pow(2, 5);
    printf("%d ", result);
}