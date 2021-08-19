#include <stdio.h>

struct Matrix
{
    int A[20];
    int n;
};
//LowerTrianguar Matrices
void setLower(struct Matrix *m, int i, int j, int x)
{
    int rowMajor = i * (i - 1) / 2 + (j - 1);
    if (i >= j)
    {
        m->A[rowMajor] = x;
    }
}
int Get(struct Matrix *m, int i, int j)
{
    int rowMajor = i * (i - 1) / 2 + (j - 1);
    if (i >= j)
    {
        return m->A[rowMajor];
    }
    else
    {
        return 0;
    }
}
void Display(struct Matrix m)
{
    int i, j;
    int rowMajor;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i >= j)
            {
                rowMajor = i * (i+1) / 2 + (j);
                printf("%d ", m.A[rowMajor]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main()
{

    struct Matrix m;
    m.n = 3;
    setLower(&m, 1, 1, 5);
    setLower(&m, 2, 1, 6);
    setLower(&m, 2, 2, 7);
    setLower(&m, 3, 1, 8);
    setLower(&m, 3, 2, 10);
    setLower(&m, 3, 3, 11);
    Display(m);
    int r = Get(&m, 2, 2);
    printf("%d\n", r);
}