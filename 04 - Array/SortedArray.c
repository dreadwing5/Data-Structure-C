#include <stdio.h>
#include <string.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{

    int Arr[10] = {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2};
    //Sort this array negative number will be on the left side and positive number will be on the right side


    for (int i = 1; i < 10; i++)
    {
        //Check for the preceding element
        for (int j = 0; j<i; j++)
        {
            if (Arr[i] <Arr[j])
            {
                swap(&Arr[i],&Arr[j]);
            }
        }
    }
    printf("\nThe Sorted Array is : ");
    for (int i = 0; i <10; i++)
    {
        printf("%d ",Arr[i]);
    }
    printf("\n\n");
    return 0;
    
}