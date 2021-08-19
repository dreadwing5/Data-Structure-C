/* Name - Sachin Kumar
  Roll - E59
  Binary Search*/
#include<stdio.h>
int main()
{
  int a[20],i,j,temp,n,x,start,end,mid;
  printf("Enter The Number of Elements : "  );
  scanf("%d",&n);
  printf("Enter The Integers :\n");
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<n-1-i;j++)
      {
        if(a[j]>a[j+1])
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
        }
      }
    }
    printf("Sorted list in ascending order:\n");
    for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }
  printf("Enter The Elements to be Searched\n");
  scanf("%d",&x);
  start=0;
  end=n-1;
  mid=(start+end)/2;
  while(start<=end)
  {
    if(a[mid]==x)
    {
      printf("%d is in array\n",x);
      return -1;
    }
    else if(a[mid]>x)
    {  end=mid-1;
    }
    else if(a[mid]<x)
    {
    start=mid+1;
    }
    mid=(start+end)/2;
  }
    printf("%d is not in array\n",x);
return 0;
}
