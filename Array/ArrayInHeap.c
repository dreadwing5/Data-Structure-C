#include <stdlib.h>
#include <stdio.h>

void main()
{

    int *A[3]; //Array of integer pointer
    int **B;
    for (int i = 0; i < 3; i++)
    {
        A[i] = (int *)malloc(4 * sizeof(int)); // Array
    }
    printf("The Elements in the array A are : \n"); //It will display garbage value

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    //Storing 2D array inside heap
    B = (int **)malloc(4 * sizeof(int *)); //B points to an array of apointer in heap segment

    for (int i = 0; i < 3; i++)
    {
        B[i] = (int *)malloc(4 * sizeof(int)); //The arrays are created in array
    }
    printf("The Elements in the array B are : \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}