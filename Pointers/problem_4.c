#include <stdio.h>

int addTwoNumbers(int *a, int *b) ;
void main()
{
    int num1, num2, result;
    printf("Enter 1st Number : ");
    scanf("%d", &num1);
    printf("Enter 2nd Number : ");
    scanf("%d", &num2);
    result = addTwoNumbers(&num1,&num2);
    printf("The Sum is : %d\t",result );

}
int addTwoNumbers(int *a, int *b){
    int sum;
    sum = *a + *b;
    return sum;


}