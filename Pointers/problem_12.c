#include <stdio.h>
#include<string.h>

void main()
{
    char s[20];
    char *p = s;
    int vowelCounter = 0;
    int consCounter = 0;
    printf("Enter a String : ");
    scanf("%s", s);
    int i =0;
    while (i<strlen(s))
    {
        if (*(p+i) == 'a' || *(p+i) == 'e' || *(p+i) == 'i' || *(p+i) == 'o' || *(p+i) =='u')
        {
            vowelCounter++;
        }
        else
        {
            consCounter++;
        }
        i++;
    }

    printf("No. of Vowels is :  %d\n",vowelCounter);
    printf("No. of Consonant is : %d\n",consCounter);
}