#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10]; //Dynamically store elements in the array
    int sizeOfArray;
    int length;
};

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->sizeOfArray = 10;

    return arr3;
}
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i]<arr2->A[j] | arr1->A[i]> arr2->A[j])
        {
            i++;
            j++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->sizeOfArray = 10;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] == arr2->A[j])
        {

            i++;
            j++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->sizeOfArray = 10;

    return arr3;
}

void DisplayArray(struct Array *arr)
{
    printf("The Array is : ");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

int main()
{
    //Structure Decleration
    struct Array arr1 = {{2, 3, 4, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 20}, 10, 5};
    struct Array *arr3;
    arr3 = Difference(&arr1, &arr2);
    DisplayArray(arr3);
}