#include <stdio.h>
#include <stdlib.h>

int main()
{

    int A[5] = {3, 8, 16, 20, 25};
    int B[5] = {4, 10, 12, 22, 23};
    int C[10];

    int i, j, k;
    i = j = k = 0;
    while (i < 5 && j < 5)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }

        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    //This is done to copy the last element in the array
    
    for (; i < 5; i++)
    {
        C[k] = A[i];
    }
    for (; j < 5; j++)
    {
        C[k] = B[j];
    }

    for (int k = 0; k < 10; k++)
    {
        printf("%d ", C[k]);
    }
}