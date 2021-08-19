/* Permutation of a string  using pointer */

/* Write a program in C to compute the sum of all elements in an array using pointers. */

#include<stdio.h>
void main(){
    int a[5]= {1,2,3,4,5};
    int *pt = a;
    int sum = 0;
    for(int i=0;i<5;i++){
        sum += *pt;
        *pt++;
    }
    printf("sum is : %d",sum);


}