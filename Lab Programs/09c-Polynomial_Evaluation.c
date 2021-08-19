//This program is simpler version of polynomial evaluation.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{
    int coeff, pow;
    char var;
    struct polynomial *link;
};

typedef struct polynomial *POLYNOMIAL;
POLYNOMIAL head = NULL;

POLYNOMIAL create()
{
    POLYNOMIAL getnode;
    getnode = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    if (getnode == NULL)
    {
        printf("\nMemory couldnt be allocated!!!");
        return NULL;
    }
    return getnode;
}

void insert(int c, int p, char var)
{
    POLYNOMIAL temp, last;
    temp = create();
    temp->coeff = c;
    temp->pow = p;
    temp->var = var;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        last = head;
        head->link = head;
    }
    else
    {
        last->link = temp;
        last = temp;
        last->link = head;
    }
}



void display()
{
    int count = 1;
    POLYNOMIAL temp = head;
    do
    {
        printf("%d%c^%d ", temp->coeff, temp->var, temp->pow);
        if (count < 3)
        {
            printf("+ ");
        }
        count++;
        temp = temp->link;
    } while (temp != head);
}

int evaluate_polynomial()
{
    int vx, vy, vz, sum = 0;
    int count = 1;
    int vPow;
    POLYNOMIAL temp = head;
    printf("\n\nEnter the value of x, y and z: ");
    scanf("%d%d%d", &vx, &vy, &vz);
    do
    {

        if (count == 1)
        {
            vPow = vx;
        }
        else if (count == 2)
        {
            vPow = vy;
        }
        else
        {
            vPow = vz;
        }
        sum = sum + (temp->coeff * pow(vPow, temp->pow));
        temp = temp->link;
        count++;
    } while (temp != head);
    return sum;
}

int main()
{
    int x, y, z, powx, powy, powz, res;
    printf("\nEnter the polynomial to be evaluated: \n");

    printf("Enter The Coffecient of x : ");
    scanf("%d", &x);
    printf("Enter the Power of x: ");
    scanf("%d", &powx);

    printf("Enter The Coffecient of y : ");
    scanf("%d", &y);
    printf("Enter the Power of y: ");
    scanf("%d", &powy);

    printf("Enter The Coffecient of z : ");
    scanf("%d", &z);
    printf("Enter the Power of z: ");
    scanf("%d", &powz);

    insert(x, powx, 'x');
    insert(y, powy, 'y');
    insert(z, powz, 'z');
    printf("\nThe given polynomial is: ");
    display();
    res = evaluate_polynomial();
    printf("\nThe result after evaluation is: %d\n", res);
}