#include <stdio.h>

int main()
{
    char STR[100], PAT[20], ANS[100], REP[20];
    int c = 0, m = 0, i = 0, j = 0, k, flag = 0;
    printf("\nEnter The Main String : \n");
    gets(STR);

    printf("\nEnter Pattern String : \n");
    gets(PAT);
    printf("\nEnter Replacement String : \t");
    gets(REP);

    while (STR[c] != '\0')
    {
        if (STR[m] == PAT[i])
        {
            m++;
            i++;
            if (PAT[i] == '\0')
            {
                flag = 1; //Pattern Was found
                for (k = 0; REP[k] != '\0'; k++, j++)
                {
                    ANS[j] = REP[k]; //Copy the contents of replacement string to answer string
                }
                c = m;
                i = 0;
            }
        }

        else
        {
            ANS[j] = STR[c]; //Copy the content of main  String to final String
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    if (flag == 0)
    {
        printf("Pattern wasn't  found!\n");
    }
    else
    {
        ANS[j] = '\0';
        printf("%s\n", ANS);
    }
    return 0;
}