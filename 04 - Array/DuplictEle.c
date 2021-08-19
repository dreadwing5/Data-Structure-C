//To find duplicate elements and count the occurance

#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[20];
    int sizeOfArray;
    int length;
};

//Duplicate element in a sorted array
void duplicateElements(struct Array arr)
{
    int i, j;
    for (i = 0; i < arr.length - 2; i++)
    {
        j = i + 1;
        if (arr.A[i] == arr.A[i + 1])
        {
            while (arr.A[j] == arr.A[i])
            {
                j++;
            }
            printf("Dulicate item %d is appearing %d times\n", arr.A[i], j - i);
            i = j - 1;
        }
    }
}
//Using HashTable
//Best method if max element of an array is small
//Time Complexity : O(n)
void duplicateElements1(struct Array arr, int *H, int max)
{

    for (int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        if (H[i] > 1)
        {
            printf("Duplicate item %d is appearing %d times\n", i, H[i]);
        }
    }
}

//Unsorted Array without usung hash table
//Best method for finding duplicate if array contains large numbeers
//Time complexity : O(n^2)
void duplicateElements2(struct Array arr)
{
    int count;
    for (int i = 0; i < arr.length; i++)
    {
        int count = 0; //Set the count to 0 each time after finding duplicate items
        if (arr.A[i] != -1)
        {
            //Scan through sub Array to find matchin pair
            for (int j = i + 1; j < arr.length; j++)
            {
                //If a matching pair is found increase count and set the value to -1
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1; //This is done to avoid checking the same ele in the next scan
                }
            }
            if (count >=1)
            {
                printf("\nDuplicate item %d is appearing %d times", arr.A[i], count + 1);
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

int main()
{
    struct Array arr = {{6, 2, 3, 6, 5, 5, 8, 9, 9, 9}, 15, 10};
    struct Array arr1 = {{666, 2, 3, 666, 52, 52, 8, 98, 98, 98}, 15, 10};
    int max = Max(arr);
    int *H;
    H = (int *)calloc(max + 1, sizeof(int));
    duplicateElements1(arr, H, max + 1);
    duplicateElements2(arr1);
    printf("\n");
    return 0;
}