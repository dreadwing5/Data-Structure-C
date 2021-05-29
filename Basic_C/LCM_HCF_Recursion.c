#include <stdio.h>

int hcf(int, int);
int lcm(int, int);

int main()
{
    int a, b, result;

    printf("Enter the two numbers: ");
    scanf("%d%d", &a, &b);
    result = lcm(a, b);
    printf("The LCM of %d and %d is %d\n", a, b, result);
    result = hcf(a, b);
    printf("The HCF of %d and %d is %d.\n", a, b, result);
}

int hcf(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            return hcf(a - b, b);
        }
        else
        {
            return hcf(a, b - a);
        }
    }
    return a;
}
int lcm(int a, int b)
{
    static int common = 1;

    if (common % a == 0 && common % b == 0)
    {
        return common;
    }
    common++;
    lcm(a, b);
    return common;
}
