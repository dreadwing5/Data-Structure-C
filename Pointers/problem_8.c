/* Write a program in C to print the elements of an array in reverse order. */
#include <stdio.h>
void main()
{

    int a[] = {1, 2, 3, 4, 5,6,7,8,9,10,11,12};
    int *p = a;
    int n =12;
    int i,temp,j=n-1;
    for(i=0;i<(n)/2;i++){
        temp=*(p+i);
        *(p+i) = *(p+j);
        *(p+j) = temp;
        j--;
    }
    for (int k = 0; k < n; k++)
    {
        printf("%d",a[k]);
    }
}