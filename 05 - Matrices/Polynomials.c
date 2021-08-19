#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *T;
};
void Create(struct Poly *P)
{
    printf("Enter the total terms in polynomial : ");
    scanf("%d", &P->n);
    P->T = (struct Term *)malloc(P->n * sizeof(struct Term));
    for (int i = 0; i < P->n; i++)
    {
        printf("Enter %d Term : ", i + 1);
        scanf("%d%d", &P->T[i].coff, &P->T[i].exp);
    }
}
struct Poly *add(struct Poly *P1, struct Poly *P2)
{
    struct Poly *Sum;
    Sum = (struct Poly *)malloc(sizeof(struct Poly));
    Sum->T = (struct Term *)malloc((P1->n + P2->n) * sizeof(struct Term));
    int i, j, k;
    i = j = k = 0;
    while (i < P1->n || j < P2->n)
    {
        if (P1->T[i].exp > P2->T[j].exp)
        {
            Sum->T[k++] = P1->T[i++];
        }
        else if (P1->T[i].exp < P2->T[j].exp)
        {
            Sum->T[k++] = P2->T[j++];
        }
        else
        {
            Sum->T[k] = P1->T[i];
            Sum->T[k++].coff = P1->T[i++].coff + P2->T[j++].coff;
        }
    }

    for (; i < P1->n; i++)
    {
        Sum->T[k++] = P1->T[i];
    }
    for (; j < P2->n; j++)
    {
        Sum->T[k++] = P2->T[j];
    }
    Sum->n = k;
    return Sum;
}

void Display(struct Poly P)
{
    for (int i = 0; i < P.n; i++)
    {
        printf("%dx^%d ", P.T[i].coff, P.T[i].exp);
        if (i != P.n - 1)
        {
            printf("+ ");
        }
    }
    printf("\n");
    printf("\n");
}

int main()
{
    struct Poly P1, P2, *P3;
    Create(&P1);
    Create(&P2);
    P3 = add(&P1, &P2);
    printf("\n");
    printf("Polynomial 1 is : ");
    Display(P1);
    printf("Polynomial 2 is : ");
    Display(P2);
    printf("The Sum of Polynomial is : ");
    Display(*P3);
}