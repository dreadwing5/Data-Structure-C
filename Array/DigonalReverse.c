#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void ReverseDiagonal(int N, int **Arr)
{
    //Reverse Diagonal
    for (int i = 0, j = N-1; i < j; i++, j--)
    {
        Swap(&Arr[i][i], &Arr[j][j]);//Reverse Principal Diagonal
        Swap(&Arr[i][j], &Arr[j][i]); //Reverse  Secondary Diagonal
    }
}
int main()
{
    int N; //N = Size Of Square Matrix
    printf("Enter The Size Of A  Square Matrix : ");
    scanf("%d", &N);
    // Dynamically create array of pointers of size N
    int **Arr = (int **)malloc(N * sizeof(int *));

    //Dynamically allocate memory of size N  for each row
    for (int i = 0; i < N; i++)
        Arr[i] = (int *)malloc(N * sizeof(int));
    //Input The Elements in Dynamically Created Array
    printf("Enter The Elements Of The Array : \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &Arr[i][j]);
        }
    }
    printf("Original Array is : \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", Arr[i][j]);
        }
        printf("\n");
    }
    ReverseDiagonal(N, Arr);

    printf("Reversed Array is : \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", Arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}