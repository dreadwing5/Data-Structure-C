#include <stdio.h>

int main() {
    double phy,chem,maths,bio,comp,sum=0,percent;
    printf("Enter marks out of 100 for physics:\n");
    scanf("%lf",&phy);
    printf("Enter marks out of 100 for chemistry:\n");
    scanf("%lf",&chem);
    printf("Enter marks out of 100 for Biology:\n");
    scanf("%lf",&bio);
    printf("Enter marks out of 100 for Mathematics:\n");
    scanf("%lf",&maths);
    printf("Enter marks out of 100 for computer:\n");
    scanf("%lf",&comp);
    sum=maths+chem+bio+phy+comp;
    percent=(sum/500)*100;
    printf("Percentage=%lf\n",percent);
    if(percent>=90)
        printf("Grade A");
    else if(percent>=80 && percent<90)
        printf("Grade B");
    else if(percent>=70 && percent<80)
        printf("Grade C");
    else if(percent>=60 && percent<70)
        printf("Grade D");
    else if(percent>=40 && percent<60)
        printf("Grade E");
    else
        printf("Grade F");
    return 0;
}
