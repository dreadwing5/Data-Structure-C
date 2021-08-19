#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int n)
{
    int key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {5, 4, 7, 8, 2};
    int size = sizeof(A) / sizeof(int);
    insertionSort(A, size);
    printf("The Sorted Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}