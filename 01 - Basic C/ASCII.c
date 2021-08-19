#include <stdio.h>

int main()
{
    char ch = 'z';
    printf("Alphabets from a - z are: \n");
    while(ch>='a')
    {
        printf("%c\n", ch);
        ch--;
    }

    return 0;
}
