
// Design, Develop and Implement a menu driven Program in C for the following operations on Doubly Linked
// List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
// a. Creating a DLL of N Employees Data by using end insertion
// b. Display the status of DLL and count the number of nodes in it
// c. Perform Insertion / Deletion at End of DLL
// d. Perform Insertion / Deletion at Front of DLL
// e. Demonstrate how this DLL can be used as Double Ended Queue
// f. Exit

#include <stdio.h>
#include <stdlib.h>

int flag = 0;

struct employee
{ // Declaring of Employee structure
    struct employee *prev;
    char ssn[20];
    char name[20];
    char dept[10];
    char designation[20];
    int sal;
    int phNO;
    struct employee *next;
};
typedef struct employee *EMPLOYEE; //Use alias for comfort
EMPLOYEE first = NULL;
EMPLOYEE last = NULL;

//Creating(Adding) a new employee
EMPLOYEE create()
{

    EMPLOYEE emp;
    emp = (EMPLOYEE)malloc(sizeof(struct employee));

    if (emp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("\nEnter the data:\n"); // Entering the details of new employee
    printf("SSN: ");
    scanf("%s", emp->ssn);
    printf("Name: ");
    scanf(" %[^\n]", emp->name);
    printf("Department: ");
    scanf("%s", emp->dept);
    printf("Designation: ");
    scanf(" %[^\n]", emp->designation);
    printf("Sallery: ");
    scanf("%d", &emp->sal);
    printf("PhNo. : ");
    scanf("%d", &emp->phNO);
    emp->prev = emp->next = NULL;
    if (flag == 0)
    {
        if (first == NULL)
        {
            first = emp;
            last = first;
        }
        else
        {
            emp->next = last->next;
            emp->prev = last;
            last->next = emp;
            last = emp;
        }
    }

    return emp;
}
int Length(EMPLOYEE P)
{
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

void insertNode(EMPLOYEE P, int index)
{
    //Check for valid indexition
    if (index < 0 || index > Length(first))
    {
        return;
    }
    else
    {
        EMPLOYEE emp, temp;
        emp = create();
        if (index == 0)
        {
            temp = emp;
            //Insertion at Front Node

            temp->next = first;
            temp->prev = NULL;
            first->prev = temp;
            first = temp;
        }

        //Inserting ELement at any index

        else
        {
            temp = emp;
            EMPLOYEE q;
            q = first;
            int i = 0;

            while (i < index)
            {
                q = P;
                P = P->next;
                i++;
            }
            if (!P)
            {
                temp->prev = q;
                temp->next = NULL;
                q->next = temp;
            }
            else
            {
                temp->prev = P->prev;
                temp->next = q->next;
                q->next = temp;
                P->prev = temp;
            }
        }
    }
}

void deleteNode(EMPLOYEE P, int index)
{
    if (index < 0 || index > Length(first))
    {
        return;
    }
    else
    {

        if (index == 0)
        {

            P = first->next;
            P->prev = NULL;
            free(first);
            first = P;
        }
        else
        {
            EMPLOYEE q;
            q = first;
            int i = 0;

            while (i < index)
            {
                q = P;
                P = P->next;
                i++;
            }
            if (!P->next)
            {
                q->next = NULL;
                free(P);
            }
            else
            {
                q->next = P->next;
                P->next->prev = P->prev;
                free(P);
            }
        }
    }
}

void Display(EMPLOYEE P)
{
    if (first == NULL)
    {
        printf("No Employee to Display!\n");
    }
    printf("The number of Employee in the list are: %d\n", Length(first));
    printf("The details of the employee are: \n");
    while (P != NULL)
    {
        printf("\nSSN: ");
        printf(" %s", P->ssn);
        printf("\nName: ");
        printf(" %s", P->name);
        printf("\nDepartment: ");
        printf(" %s", P->dept);
        printf("\nDesignation: ");
        printf(" %s", P->designation);
        printf("\nPhNo. : ");
        printf(" %d", P->phNO);
        printf("\n Sallery : ");
        printf("%d", P->sal);
        printf("\n");
        P = P->next;
    }
}

int main()
{
    int ch, n, i, index;
    while (1)
    {
        printf("\n1: Create N details\n2: Insert\n3: Delete\n4: Display\n5: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number of Employees: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                create();
            }
            flag = 1;
            break;
        case 2:
            printf("Enter The index at which the data has to be inserted : ");
            scanf("%d", &index);
            insertNode(first, index);
            break;
        case 3:
            printf("Enter The index at which the data has to be deleted:  ");
            scanf("%d", &index);
            deleteNode(first, index);
            break;
        case 4:
            Display(first);
            break;
        case 5:
            return 0;
        default:
            printf("\nInvalid Choice!!!\n");
        }
    }
}