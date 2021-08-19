#include <stdio.h>

void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}

int partioning(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++; //Increase i as long as i is less than pivot, imagine shorter people should be in front line
        } while (pivot >= A[i]);
        do
        {
            j--;
        } while (pivot < A[j]);
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }

    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partioning(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}

int main()
{
    int A[] = {8, 6, 3, 2, 5, 4, __INT_MAX__};
    int size = sizeof(A) / sizeof(int);
    quickSort(A, 0, size - 1);
    printf("The Sorted Array is : ");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", A[i]);
    }
}