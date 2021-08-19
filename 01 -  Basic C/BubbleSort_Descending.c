#include<stdio.h>
int main()
{
  int a[20],i,j,temp,n;
  printf("Enter The Number of Elements : "  );
  scanf("%d",&n);
  printf("Enter The Integers :\n");
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        if(a[i]>a[j])
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
    }
    printf("Sorted list in descending order:\n");
    for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }
    return 0;

}
