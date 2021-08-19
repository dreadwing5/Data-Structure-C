#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int A[], int n)
{
    int j, k;
    for (int i = 0; i < n - 1; i++)
    {
        j = k = i;
        while (k < n)
        {
            if (A[j] > A[k])
            {
                j = k;
                k++;
            }
            else
            {
                k++;
            }
        }
        swap(&A[i], &A[j]);
    }
}

int main()
{
    int A[] = {8, 6, 3, 2, 5, 4};
    int size = sizeof(A) / sizeof(int);
    selectionSort(A, size);
    printf("The Sorted Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}