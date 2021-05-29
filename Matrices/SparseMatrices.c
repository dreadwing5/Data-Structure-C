#include <stdio.h>
#include <stdlib.h>

struct Elements
{
    int i; //Row of sparse matrix
    int j; //Column
    int x; //Element to be stored at the given row and column
};
struct Sparse
{
    //Dimension of sparse matrix
    int m;
    int n;
    int num;            // Total no of elements to be stored
    struct Elements *e; //Dynamically generate Array Of Structure
};

void Create(struct Sparse *S)
{
    int i;
    printf("Enter The Dimension of Matrix\n");
    printf("Enter No. Of Row : ");
    scanf("%d", &S->m);
    printf("Enter No. OF Column : ");
    scanf("%d", &S->n);
    printf("Enter The Total No. of Non-zero Elements : ");
    scanf("%d", &S->num);
    S->e = (struct Elements *)malloc(S->num * sizeof(struct Elements)); //Dynamic Array of Structure
    printf("Enter All Non-Zero Elements (i,j,x) : \n");
    for (i = 0; i < S->num; i++)
    {
        scanf("%d%d%d", &S->e[i].i, &S->e[i].j, &S->e[i].x);
    }
}
void Display(struct Sparse S)
{
    int i, j, k = 0;
    for (i = 0; i < S.m; i++)
    {
        for (j = 0; j < S.n; j++)
        {
            if (i == S.e[k].i && j == S.e[k].j)
            {
                printf("%d ", S.e[k].x);
                k++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
//Function returning a pointer
struct Sparse *Add(struct Sparse *A, struct Sparse *B)
{
    struct Sparse *Sum;
    if (A->m != B->m || A->n != B->n)
    {
        return NULL;
    }
    Sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    Sum->e = (struct Elements *)malloc((A->num + B->num) * sizeof(struct Elements));
    int i, j, k;
    i = j = k = 0;
    while (i < A->num && j < B->num)
    {
        if (A->e[i].i < B->e[j].i)
        {
            Sum->e[k++] = A->e[i++];
        }
        else if (A->e[i].i > B->e[j].i)
        {
            Sum->e[k++] = B->e[j++];
        }
        else
        {
            if (A->e[i].j < B->e[j].j)
            {
                Sum->e[k++] = A->e[i++];
            }
            else if (A->e[i].j > B->e[j].j)
            {
                Sum->e[k++] = B->e[j++];
            }
            else
            {
                Sum->e[k] = A->e[i];
                Sum->e[k++].x = A->e[i++].x + B->e[j++].x;
            }
        }
    }
    for (; i < A->num; i++) //Fillup the leftover elements
        Sum->e[k++] = A->e[i];
    for (; j < B->num; j++)
        Sum->e[k++] = B->e[j];
    Sum->m = A->m;
    Sum->n = A->n;
    Sum->num = k;
    return Sum;
}

int main()
{
    struct Sparse A, B, *S;//Function will be returning a pointer to a structure
    Create(&A);
    Create(&B);
    S = Add(&A, &B);
    printf("\n");
    Display(A);
    printf("\n");
    Display(B);
    printf("\n");
    Display(*S);
}