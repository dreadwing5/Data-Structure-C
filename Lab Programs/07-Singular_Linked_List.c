/* Desist, Develop and Implement a menu driven Program in C for the following operations on Singly nexted List (SLL) of Student Data with the fields: USN, Name, Programme, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit */

#include <stdio.h>
#include <stdlib.h>

struct student
{ // Declaring of student structure
    char usn[20];
    char name[20];
    char programme[10];
    int sem;
    int phNO;
    struct student *next;
};

typedef struct student *STUDENT; // Using Alias for comfort :)
STUDENT first = NULL;
STUDENT st = NULL;
int count = 0;

STUDENT create()
{ // Creation(Adding) a new student

    st = (STUDENT)malloc(sizeof(struct student)); // Using dynamic memory allocation

    if (st == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("\nEnter the data:\n"); // Entering the details of new student
    printf("USN: ");
    scanf("%s", st->usn);
    printf("Name: ");
    scanf(" %[^\n]", st->name);
    printf("programme: ");
    scanf("%s", st->programme);
    printf("SEM: ");
    scanf("%d", &st->sem);
    printf("PhNo. : ");
    scanf("%d", &st->phNO);
    st->next = NULL;
    return st;
}

void insert_front()
{

    st = create();
    if (first == NULL) // If list is empty
        first = st;
    else
    { // else
        st->next = first;
        first = st;
    }
    count++;
}

void display()
{
    STUDENT temp;
    if (first == NULL)
    { // No student to display
        printf("No student to Display!!!\n");
    }
    else
    {
        temp = first;
        printf("The number of student in the list are: %d\n", count);
        printf("The details of the student are: \n");
        while (temp != NULL)
        {
            printf("\nUSN: ");
            printf(" %s", temp->usn);
            printf("\nName: ");
            printf(" %s", temp->name);
            printf("\nprogramme: ");
            printf(" %s", temp->programme);
            printf("\nSEM: ");
            printf(" %d", temp->sem);
            printf("\nPhNo. : ");
            printf(" %d", temp->phNO);
            printf("\n");
            temp = temp->next;
        }
    }
}

void delete_front()
{
    STUDENT temp;

    if (first == NULL) // When List is Already empty
        printf("The list is empty!!!\n");

    else
    {
        temp = first;
        first = first->next;
        printf("The removed student is: ");
        printf("\nStudent data:");
        printf("\nUSN: ");
        printf(" %s", temp->usn);
        printf("\nName: ");
        printf(" %s", temp->name);
        printf("\nprogramme: ");
        printf(" %s", temp->programme);
        printf("\nSEM: ");
        printf(" %d", temp->sem);
        printf("\nPhNo. : ");
        printf(" %d", temp->phNO);
        printf("\n");
        free(temp);
        count--;
    }
}

void insert_rear()
{
    STUDENT temp;
    st = create();

    if (first == NULL)
    { // When List is empty
        first = st;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = st;
    }
    count++;
}

void delete_rear()
{
    STUDENT temp, prev;

    if (first == NULL) // List is Already empty
        printf("List is empty!\n");
    else if (first->next == NULL)
    { // When list has only one student
        printf("The removed student is: ");
        printf("\nStudent data:");
        printf("\nUSN: ");
        printf(" %s", temp->usn);
        printf("\nName: ");
        printf(" %s", temp->name);
        printf("\nprogramme: ");
        printf(" %s", temp->programme);
        printf("\nSEM: ");
        printf(" %d", temp->sem);
        printf("\nPhNo. : ");
        printf(" %d", temp->phNO);
        printf("\n");
        first = NULL;
        count--;
    }
    else
    {
        temp = first;
        prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        printf("\nThe removed student is : ");
        printf("\nStudent data:");
        printf("\nUSN: ");
        printf(" %s", temp->usn);
        printf("\nName: ");
        printf(" %s", temp->name);
        printf("\nprogramme: ");
        printf(" %s", temp->programme);
        printf("\nSEM: ");
        printf(" %d", temp->sem);
        printf("\nPhNo. : ");
        printf(" %d", temp->phNO);
        printf("\n");
        free(temp);
        prev->next = NULL;
        count--;
    }
}

void insert_pos()
{
    STUDENT stode, temp, prev;
    stode = create();

    int pos, i = 1;
    printf("Enter the position to be inserted: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > count)
    {
        printf("Invalid position");
        return;
    }

    if (first == NULL && pos == 1)
    {
        first = stode;
    }
    else
    {
        temp = first;
        prev = NULL;

        while (temp != NULL)
        {
            if (pos == i)
                break;
            else
            {
                i++;
                prev = temp;
                temp = temp->next;
            }
        }

        prev->next = stode;
        stode->next = temp;
    }
    count++;
}

int main()
{
    int ch, n, i;

    while (1)
    {
        printf("\n1: Create N details\n2: Insert Front\n3: Delete Front\n4: Insert End\n5: Delete End\n6: Display Status\n7:Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the number of students: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++)
                insert_front();

            break;
        case 2:
            insert_front();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            insert_rear();
            break;
        case 5:
            delete_rear();
            break;
        case 6:
            display();
            break;
        case 7:
            return 0;

        default:
            printf("\nInvalid Choice !!!\n");
        }
    }
}