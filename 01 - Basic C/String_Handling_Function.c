/* Name- Sachin Kumar
    Roll- E59
  */
#include<stdio.h>
int stringlength(char s[])
{
  int i;
  for (i = 0;s[i]!= '\0';i++);

  return i;
}
void stringcompare(char s1[], char s2[])
{
  int i;
  for (i=0;(s1[i]!= '\0') && (s1[i]==s2[i]) ;i++)
  ;
  {
    if(s1[i]<s2[i])
    {
    printf("\n%s is less than %s",s1,s2);
    }
    else if(s1[i]>s2[i])
    {
      printf("\n%s is greater than %s",s1,s2);
    }
    else
    {
      printf("%s is equal to %s",s1,s2);
    }
  }
}
void stringconcat(char s1[], char s2[])
{
  int i,j;
  i = stringlength(s1);
  for(j=0;s2[j]!='\0';j++,i++)
  {
      s1[i]=s2[j];
  }

  s1[i] = '\0';
  printf("\nConcatinated String is : %s",s1);
}

int main(void)
{
  char s1[20];
  char s2[20];
  printf("Enter the value of  string1 : ");
  gets(s1);
  printf("Enter the value of  string1 : ");
  gets(s2);
  printf("\nLength of the string %s is %d\n", s1, stringlength(s1));
  printf("\nLength of the string %s is %d\n", s2, stringlength(s2));

  stringcompare(s1,s2);
  stringconcat(s1,s2);
}
