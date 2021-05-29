#include<stdio.h>
void stringcompare(char s1[], char s2[])
{
  int i;
  for(i=0;(s1[i]!= '\0') && (s1[i]==s2[i]) ;i++)
  ;
  {
    if(s1[i]<s2[i])
    {
    printf("%s is less than %s",s1,s2");
    }
    else if(s1[i]>s2[i])
    {
      printf("%s is greater than %s,s1,s2");
    }
    else
    {
      printf("%s is equal to %s",s1,s2);
    }
  }
}
int main(void)
{
  char s1[20];
  char s2[20];
  printf("Enter the value of  string1 : ");
  gets(s1);
  printf("Enter the value of  string1 : ");
  gets(s2);
  stringcompare(s1,s2);
}
