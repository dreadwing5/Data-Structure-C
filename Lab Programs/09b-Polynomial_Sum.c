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

POLYNOMIAL insert_end(POLYNOMIAL head, int c, int px, int py, int pz)
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
    head = insert_end(head, c, px, py, pz);
  }
  return (head);
}

void display(POLYNOMIAL head)
{
  POLYNOMIAL temp;
  if (head->link == head)
  {
    printf("\nPolynomial doesnt exist!!!");
    return;
  }
  temp = head->link;
  while (temp != head)
  {
    printf("%dx^%dy^%dz^%d + ", temp->coeff, temp->x, temp->y, temp->z);
    temp = temp->link;
  }
  printf("999");
}

POLYNOMIAL sum_polynomial(POLYNOMIAL head1, POLYNOMIAL head2, POLYNOMIAL head3)
{
  POLYNOMIAL p1, p2;
  int c, c1, c2, x1, y1, z1, x2, y2, z2, flag;
  p1 = head1->link;
  while (p1 != head1)
  {
    c1 = p1->coeff;
    x1 = p1->x;
    y1 = p1->y;
    z1 = p1->z;
    p2 = head2->link;
    flag = 0;
    while (p2 != head2)
    {
      c2 = p2->coeff;
      x2 = p2->x;
      y2 = p2->y;
      z2 = p2->z;
      if ((x1 == x2) && (y1 == y2) && (z1 == z2))
      {
        head3 = insert_end(head3, c1 + c2, x1, y1, z1);
        p2->coeff = 0;
        flag = 1;
        break;
      }
      else
        p2 = p2->link;
    }
    if (flag == 0)
      head3 = insert_end(head3, c1, x1, y1, z1);
    p1 = p1->link;
  }
  p2 = head2->link;
  while (p2 != head2)
  {
    if (p2->coeff != 0)
      head3 = insert_end(head3, p2->coeff, p2->x, p2->y, p2->z);
    p2 = p2->link;
  }
  return head3;
}
int main()
{
  POLYNOMIAL head1, head2, head3;
  head1 = create();
  head1->link = head1;
  head2 = create();
  head2->link = head2;
  head3 = create();
  head3->link = head3;
  printf("\nEnter the first polynomial: ");
  head1 = input_polynomial(head1);
  display(head1);
  printf("\n\nEnter the second polynomial: ");
  head2 = input_polynomial(head2);
  display(head2);
  head3 = sum_polynomial(head1, head2, head3);
  printf("\n\nThe sum of two polynomials is: ");
  display(head3);
  return (0);
}