#include<stdio.h>
int main()
{
  int year;
  printf("Enter the Year : \n");
  scanf("%d",&year );
  if(year%4==0)
  {
    //check for century Year
    if(year%100==0)
    {
      //check for century leap Year
      //1900 is a century yaer but not a leap Year
      if(year%400==0)
      {
        printf("It is a century year and a leap year\n");
      }
      else
      {
        printf("It is a century year but not a leap year\n");
      }
    }
    else
    {
      printf("It is not a century year but a leap year\n" );
    }
  }
  else
  {
    printf("It is not a century year and a leap year\n");
  }
return 0;
}
