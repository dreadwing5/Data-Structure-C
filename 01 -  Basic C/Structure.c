#include<stdio.h>
struct student
{
  int rno;
  char Sname[30];
  float marks;

};

int main()
{
  int N,i;
  printf("Enter The No Of Students :");
  scanf("%d",&N);
  struct student S[N];
  printf("Enter The Details Of Student %d \n",i+1);
  for(i=0;i<N;i++)
  {
    printf("Enter Student %d Roll No : ",i+1);
    scanf("%d",&S[i].rno);
    printf("Enter Student %d Name : ",i+1);
    scanf("%s",S[i].Sname);
    printf("Enter Student %d Marks : ",i+1);
    scanf("%f",&S[i].marks);
  }
  printf("\n");
  printf("Students scoring Above or Equal to 70 Marks are : \n");
  for(i=0;i<N;i++)
  {
    if(S[i].marks>=70){
    printf("%s\n",S[i].Sname);
    }

  }
return 0;
}
