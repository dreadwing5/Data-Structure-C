// The output of this program can be different 
// in different runs. Note that the program 
// prints address of a variable and a variable 
// can be assigned different address in different 
// runs. 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   /*  char inputString[100];
    gets(inputString);
    printf("Hello World!\n");
    puts(inputString);
    return 0; */
    int a= 10;
    int i = 2;
    int num = pow(a,i);
    printf("power = %d",num);
}