// C program to demonstrate declaration of 
// pointer variables. 
#include <stdio.h> 
int main()
{
    int m= 29;
    printf("Address of m : %d\n", &m);
    printf("Value of m: %d\n", m);


    // 1) Since there is * in declaration, ptr 
    // becomes a pointer varaible (a variable 
    // that stores address of another variable) 
    // 2) Since there is int before *, ptr is 
    // pointer to an integer type variable 
    int *ab;

    // & operator before x is used to get address 
    // of x. The address of x is assigned to ptr. 
    ab = &m;
    printf("Adress of pointer ab : %d\n", ab);
    printf("Content of pointer ab: %d\n", *ab);
    m=34;
    printf("Adress of pointer ab : %d\n", ab);
    printf("Content of pointer ab: %d\n", *ab);
    *ab =7;
    printf("Adress of pointer ab : %d\n", ab);
    printf("Content of m: %d\n", *ab);

    return 0;
}