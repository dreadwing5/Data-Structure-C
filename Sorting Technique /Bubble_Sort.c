#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int A[], int n)
{
    int flag; //To make it adaptive
    //Outer for loop for passes
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        //Inner for loop for swapping
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1; // set flag =1 if swaping are done in each inner loop
            }
        }
        if (flag == 0)
        {
            printf("List is already Sorted!\n");
            return;
        }
    }
}

int main()
{
    int A[] = {5, 4, 7, 8, 2};
    int size = sizeof(A) / sizeof(int);
    bubbleSort(A, size);
    printf("The Sorted Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}