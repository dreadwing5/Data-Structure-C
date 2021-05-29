#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{
    int coeff, x, y, z;
    struct polynomial *link;
};

typedef struct polynomial *POLYNOMIAL;
POLYNOMIAL create()
{
    POLYNOMIAL getnode;
    getnode = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    if (getnode == NULL)
    {
        printf("\nMemory couldnt be allocated!!!");
        return NULL;
    }
    return (getnode);
}

POLYNOMIAL insert(POLYNOMIAL head, int c, int px, int py, int pz)
{
    POLYNOMIAL node, temp;
    node = create();
    node->coeff = c;
    node->x = px;
    node->y = py;
    node->z = pz;
    node->link = NULL;
    temp = head->link;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    temp->link = node;
    node->link = head;
    return (head);
}

POLYNOMIAL input_polynomial(POLYNOMIAL head)
{
    int i, c, px, py, pz;
    printf("\nEnter 999 to end the polynomial!!!");
    for (i = 1;; i++)
    {
        printf("\nEnter the coefficient %d: ", i);
        scanf("%d", &c);
        if (c == 999)
            break;
        printf("\nEnter the power of x: ");
        scanf("%d", &px);
        printf("\nEnter the power of y: ");
        scanf("%d", &py);
        printf("\nEnter the power of z: ");
        scanf("%d", &pz);
        head = insert(head, c, px, py, pz);
    }
    return (head);
}

void display(POLYNOMIAL head)
{
    POLYNOMIAL temp;
    if (head->link == head)
    {
        printf("\nPolynomial doesnt exist!!!");
    }
    else
    {
        temp = head->link;
        while (temp != head)
        {
            printf("%dx^%dy^%dz^%d + ", temp->coeff, temp->x, temp->y, temp->z);
            temp = temp->link;
        }
        printf("999");
    }
}

int evaluate_polynomial(POLYNOMIAL head)
{
    int vx, vy, vz, sum = 0;
    POLYNOMIAL temp;
    printf("\n\nEnter the value of x, y and z: ");
    scanf("%d%d%d", &vx, &vy, &vz);
    temp = head->link;
    while (temp != head)
    {
        sum = sum + (temp->coeff * pow(vx, temp->x) * pow(vy, temp->y) * pow(vz, temp->z));
        temp = temp->link;
    }
    return (sum);
}

int main()
{
    POLYNOMIAL head;
    int res;
    head = create();
    head->link = head;
    printf("\nEnter the polynomial to be evaluated: ");
    head = input_polynomial(head);
    printf("\nThe given polynomial is: ");
    display(head);
    res = evaluate_polynomial(head);
    printf("\nThe result after evaluation is: %d", res);
    return (0);
}