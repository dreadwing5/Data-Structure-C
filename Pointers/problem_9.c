/* Write a program in C to find the largest element using Dynamic Memory Allocation */

#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,temp;
    printf("Input total number of elements(1 to 100): ");
    scanf("%d",&n);
    int *p=(int*)malloc(n*sizeof(int)); //Dynamically Allocate memory for the array
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));
        
    }
    int i;
    for(i=0;i<n-1;i++){
        if(*(p+i)>*(p+1+i)){ //Swap if the first index of array is greater than the second index
            temp = *(p+i);
            *(p+i)= *(p+1+i);
            *(p+1+i) = temp;
        } 
    }
    int result  = *(p+i);  //Store the last value since the largest value has been bublled out
    printf("%d",result);
    free(p); //free the allocated memory
}