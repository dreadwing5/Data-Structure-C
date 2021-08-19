#include<stdio.h>

int main()
{
    int n,originalN,reversedN=0,remainder;
    printf("Enter a number\n");
    scanf("%d", &n);
    originalN=n;
    while(n!=0)
    {
    remainder=n%10;
    reversedN=reversedN*10+remainder;
    n=n/10;
    }
    if (originalN == reversedN)
        printf("%d is a palindrome.", originalN);
    else
        printf("%d is not a palindrome.", originalN);
    return 0;
}
