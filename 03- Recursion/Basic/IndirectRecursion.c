#include<stdio.h>
void func_B(int n);
void func_A(int n){
    if(n>0){
        printf("%d ",n);
        func_B(n-1);
    }
}
void func_B(int n){
    if(n>1){
        printf("%d ",n);
        func_A(n/2);
    }
    
}

void main(){
    int a=20;
    func_A(20);
}