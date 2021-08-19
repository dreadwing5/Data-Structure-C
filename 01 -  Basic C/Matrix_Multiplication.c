

#include <stdio.h>
int main()
{
  int a[20][20], i, j, arow, acol, b[20][20], prod[20][20], brow, bcol, k;
  printf("Enter the number of rows and columns of Matrix A: \n");
  scanf("%d%d", &arow, &acol);
  printf("Enter the number of rows and columns of Matrix B: \n");
  scanf("%d%d", &brow, &bcol);
  if (acol != brow)
  {
    printf("Matrix multipliction is not possible\n");
    return -1;
  }
  else
  {
    printf("Enter the elements of the matrix A :\n");
    for (i = 0; i < arow; i++)
    {
      for (j = 0; j < acol; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }
    printf("Matrix A is :\n");
    for (i = 0; i < arow; i++)
    {
      for (j = 0; j < acol; j++)
      {
        printf("%d\t", a[i][j]);
      }
      printf("\n");
    }

    printf("Enter the elements of the matrix B :\n");
    for (i = 0; i < brow; i++)
    {
      for (j = 0; j < bcol; j++)
      {
        scanf("%d", &b[i][j]);
      }
    }
    printf("Matrix B is :\n");
    for (i = 0; i < brow; i++)
    {
      for (j = 0; j < bcol; j++)
      {
        printf("%d\t", b[i][j]);
      }
      printf("\n");
    }
    for (i = 0; i < arow; i++)
    {
      for (j = 0; j < bcol; j++)
      {
        prod[i][j] = 0;
        for (k = 0; k < acol; k++)
        {
          prod[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    printf("\nThe Product of Matrix A & Matrix B : \n");
    for (i = 0; i < arow; i++)
    {
      for (j = 0; j < bcol; j++)
      {
        printf("%d\t", prod[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
