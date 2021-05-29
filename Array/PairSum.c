#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int sizeOfArray;
    int length;
};

void pairSum(struct Array arr, int k)
{

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > k)
        {
            continue; //Check for next element
        }
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[j] == k - arr.A[i])
            {
                printf("\n(%d , %d)", arr.A[i], arr.A[j]);
                break;
            }
        }
    }
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
//Using HashTable
void pairSum1(struct Array arr, int *H, int max, int k)
{
    int j;
    for (int i = 0; i < arr.length; i++)
    {

        j = k - arr.A[i];
        if (H[j] != 0)
        {
            printf("\n(%d, %d)\n", arr.A[i], j);
        }
        H[arr.A[i]]++;
    }
}
//pair sum in a sorted list
void pairSum2(struct Array arr, int k)
{
    int i = 0, j = arr.length - 1, sum;
    while (i < j)
    {
        sum = arr.A[i] + arr.A[j];
        if (sum == k)
        {
            printf("\n(%d, %d)\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if (sum > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    struct Array arr = {{10, 5, 8, 3, 9, 6, 4, 1, 7, 12}, 15, 10};
    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 111}, 15, 10};
    int k = 10; //Sum to be found
    int max = Max(arr);
    int *H;
    //Dynamically creating an array of length max and instilaise each element to 0
    H = (int *)calloc(max + 1, sizeof(int));
    printf("\nPair of Sum in an Unsorted List\n");
    pairSum1(arr, H, max + 1, k);

    printf("\nPair of Sum in a Sorted List\n");
    pairSum2(arr1, k);
    printf("\n");

    return 0;
}