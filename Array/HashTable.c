//Program to find missing elements in an unsorted list using Hashtable

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int sizeOfArray;
    int length;
};

int Min(struct Array arr)
{
    int min = arr.A[0];
    int temp;
    for (int i = 1; i < arr.length; i++)
    {
        temp = arr.A[i];
        if (temp < min)
        {
            min = temp;
        }
    }
    return min;
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    int temp;
    for (int i = 1; i < arr.length; i++)
    {
        temp = arr.A[i];
        if (temp > max)
        {
            max = temp;
        }
    }
    return max;
}

void missingElements(struct Array arr, int *H, int min, int max)
{

    printf("\nThe Missing Elements are : ");
    //Set all the element present in arr to 1 in H at that index
    for (int i = 0; i < arr.length; i++)
    {
        int j = arr.A[i];
        H[j] = 1;
    }
    //check for missing element
    for (int i = min + 1; i < max + 1; i++)
    {
        if (H[i] == 0)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    struct Array arr = {{10, 5, 8, 3, 9, 6, 13, 4, 11, 12, 15}, 15, 11};
    int min = Min(arr);
    int max = Max(arr);
    int *H;
    //Dynamically creating an array of length max and instilaise each element to 0
    H = (int *)calloc(max + 1, sizeof(int));
    printf("\n");
    missingElements(arr, H, min, max);
}
