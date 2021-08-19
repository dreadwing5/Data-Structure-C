//Find out the missing element in a sorted list
#include <stdio.h>

struct Array
{

    int A[20];
    int sizeofArray;
    int length;
};

int missingElement(struct Array arr)
{

    int sum = 0, naturalSum = 0, missingEle = 0;
    int n = arr.A[arr.length - 1]; //Last Element of the array
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i]; //Find the sum of the array
        // printf("%d ",sum);
    }
    //Check if the sum is less than sum of n natural number
    naturalSum = n * (n + 1) / 2;
    missingEle = naturalSum - sum;
    return missingEle;
}
int missingElement1(struct Array arr)
{

    int missingEle = 0, n, diff;
    n = arr.A[0]; //First Element of an Array
    for (int i = 0; i < arr.length; i++)
    {
        diff = arr.A[i] - i; //Find out the difference b/w the current element & it's index
        if (diff > n)
        {
            return diff + --i;
        }
    }
}
void missingElements2(struct Array arr)
{
    int missingele = 0, n, diff;
    n = arr.A[0];
    printf("\nThe Missing Elements are : ");
    for (int i = 0; i < arr.length; i++)
    {
        diff = arr.A[i] - i; //Difference of current element & index

        while (n < diff)
        {
            printf("%d ", n + i);
            n++;
        }
    }
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11}, 15, 10};
    struct Array arr1 = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16}, 15, 10};
    struct Array arr2 = {{6, 7, 9, 10, 13, 14, 15, 16, 17, 18}, 15, 10};
    int result = missingElement1(arr1);
    printf("\nThe Missing Elment is : %d ", result);
    result = missingElement(arr);
    printf("\nThe Missing Elment is : %d ", result);
    missingElements2(arr2);

    getchar();
    return 0;
}