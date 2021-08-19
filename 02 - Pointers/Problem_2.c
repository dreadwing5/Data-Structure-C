/* Write a program in C to demonstrate the use of &(address of) and *(value at address) operator.
Expected Output :

Pointer : Demonstrate the use of & and * operator :
--------------------------------------------------------
 m = 300
 fx = 300.600006
 cht = z

 Using & operator :
-----------------------
 address of m = 0x7ffda2eeeec8
 address of fx = 0x7ffda2eeeecc
 address of cht = 0x7ffda2eeeec7

 Using & and * operator :
-----------------------------
 value at address of m = 300
 value at address of fx = 300.600006
 value at address of cht = z

Using only pointer variable :
----------------------------------
 address of m = 0x7ffda2eeeec8
 address of fx = 0x7ffda2eeeecc
 address of cht = 0x7ffda2eeeec7

 Using only pointer operator :
----------------------------------
 value at address of m = 300
 value at address of fx= 300.600006
 value at address of cht= z        */

#include<stdio.h>

void main() {

    int m=300;
    float fx=300.6;
    char cht='z';
    int *pm;
    float *pfx;
    char *pcht;
    pm = &m;
    pfx = &fx;
    pcht = &cht;
    printf("Using & operator\n");
    printf("address of m : %d\n", &m);
    printf("address of fx : %d\n", &fx);
    printf("address of cht : %d\n ", &cht);

    printf("using & and * operator\n");
    printf("value at the address of m : %d\n",*pm);
    printf("value at the address of fx : %f\n",*pfx);
    printf("value at the address of cht : %c\n",*pcht);

    printf("Using only pointer variable \n");
    printf("address of m : %d\n", pm);
    printf("address of fx : %d\n", pfx);
    printf("address of cht : %d\n ", pcht);
    



}