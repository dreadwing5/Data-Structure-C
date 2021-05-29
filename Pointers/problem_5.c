#include<stdio.h>
int findMaximum(int *a , int *b);
void main(){
    int a = 5,b=10,max;
    max = findMaximum(&a,&b);
    printf("Max = %d",max);
}
int findMaximum(int *a , int *b){
    if(*a<*b){
        return *b;
    }
    else
    {
        return *a;
    }
    
}