
/* 
Problem Statement : Define a structure for the employee with the following fields:
 Emp_Id(integer), Emp_Name(string), Emp_Dept(string) & Emp_age(integer) Empid,
DOJ (date,month,year) and salary (Basic, DA,HRA). Write the following functions to process the 
 employee data: (i) Function to read an employee record. (ii) Function to print an employee record. */

#include <stdio.h>
#include <string.h>

struct Employee
{
    int Emp_Id;
    char Emp_name[30];
    char Emp_Dept[30];
    int Emp_Age;
    struct dateOfJoining
    {
        int date;
        char month[30];
        int year;
    } doj;
    struct salary
    {
        int basic;
        int DA;
        int HRA;
    } s;

} Emp;

void ReadEmpData(struct Employee *Emp)
{
    printf("Enter Employee Name : ");
    gets(Emp->Emp_name);
    printf("Enter Employee Department : ");
    gets(Emp->Emp_Dept);
    printf("Enter Employee ID : ");
    scanf("%d", &Emp->Emp_Id);
    printf("Enter Employee Age : ");
    scanf("%d", &Emp->Emp_Age);
    printf("Enter Date Of Joining Details\n");
    printf("Enter Date : ");
    scanf("%d", &Emp->doj.date);
    printf("Enter Month : ");
    scanf("%s", Emp->doj.month);
    printf("Enter Year : ");
    scanf("%d", &Emp->doj.year);
    printf("Enter Salary Details \n");
    printf("Enter Basic Salary : ");
    scanf("%d", &Emp->s.basic);
    printf("Enter HRA : ");
    scanf("%d", &Emp->s.HRA);
    printf("Enter DA : ");
    scanf("%d", &Emp->s.DA);
}

void PrintEmpdata(struct Employee *Emp)
{
    printf("\nEmployee Name : %s", Emp->Emp_name);
    printf("\nEmployee ID : %d", Emp->Emp_Id);
    printf("\nEmployee Department : %s", Emp->Emp_Dept);
    printf("\nEmployee Age : %d", Emp->Emp_Age);
    printf("\nDate Of Joining : %d/%s/%d", Emp->doj.date, Emp->doj.month, Emp->doj.year);
    printf("\nSalary Details \nBasic Salary : %d\nHRA : %d\nDA : %d\n", Emp->s.basic, Emp->s.HRA, Emp->s.DA);
}

int main()
{
    struct Employee *Emp;
    ReadEmpData(Emp); //We are passing Structure as call by address so that it is accesible by all function
    PrintEmpdata(Emp);
    return 0;
}