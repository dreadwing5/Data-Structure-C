#include<stdio.h>
#include<stdlib.h>

int main(){

    int *A,sizeofArray,rotation;
    scanf("%d",&sizeofArray); //Dynamically Generate arrayo of length size of Array
    A=(int*)malloc(sizeofArray*sizeof(int));
    scanf("%d",&rotation); //Store How many left rotation needed to be done
    //Input Elements of array
    for(int i=0;i<sizeofArray;i++)
    {
        scanf("%d",A+i);
    }
    //Left Rotation
    int i=0,temp;
    while(i<rotation){
    temp = A[0];
    for(int k =0;k<sizeofArray;k++){
        A[k]=A[k+1];
    }
    A[sizeofArray-1]=temp;
    i++;
    }

    for(int i=0;i<sizeofArray;i++)
    {
        printf("%d ",*(A+i));
    }
return 0;
}