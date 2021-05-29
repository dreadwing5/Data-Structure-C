#include<stdio.h>
void main(){
    int n,a[n],*ptr;
    ptr = a;
    printf("Input the number of elements to store in the array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i)); 
    }
    for(int i=0;i<n;i++){
        printf("%d",*(ptr+i)); 
    }


}