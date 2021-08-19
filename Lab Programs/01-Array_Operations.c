/* Program Goals:   
     create a menu driven program
     create a variable which is going to determine the size of array dynamically
     create a variable for pos
     create an option to insert and delete
     function for accepting array
     function for displaying array
     function for inserting an element
     function for deleting an element 
     give flexibility to user so we can add or remove multiple elements in the same array */

#include <stdio.h>

//Function Declaration

void acceptElements(int *sizeOfArray, int a[]); //I've passed in pointers so that only one memory is created, I could have done this with global/static variables
void displayElements(int *sizeOfArray, int a[]);
int insertElements(int *sizeOfArray, int a[]);
int deleteElements(int *sizeOfArray, int a[]);
int input();             // Function for taking user input for Insertion or Deletion
int continueOperation(); //Function for taking user input for continution of the program
void main()
{

    int sizeOfArray, a[sizeOfArray], choice;        
    printf("---------------------------------------\n");
    printf("Enter the Size of Array : ");
    scanf("%d", &sizeOfArray);
    acceptElements(&sizeOfArray, a);
    displayElements(&sizeOfArray, a);
    int bool;
    do
    {
        printf("Press 1 for Inserting an Element...\n");
        printf("Press 2 for Deleting  an Element...\n");
        printf("Press 3 to Exit...\n");
        printf("Enter Choice! \t");
        choice = input();
        switch (choice)
        {
        case 1:
        {
            int flag = insertElements(&sizeOfArray, a);
            if (flag == 1)
            {
                return;
            }

            break;
        }
        case 2:
        {
            int flag = deleteElements(&sizeOfArray, a);
            if (flag == 1)
            {
                return;
            }
            break;
        }
        case 3:
        {
            return;
        }
        break;
        default:
        {
            printf("Wrong Input!\n");
        }
        }
        displayElements(&sizeOfArray, a);//Display The Elements in the array after each operation
        bool = continueOperation(); //Check if user wants to continue further

    } while (bool == 1);

    return;
}

//Function Definations

void acceptElements(int *sizeOfArray, int a[])
{
    printf("Enter The Elements of Array : ");
    for (int i = 0; i < *sizeOfArray; i++)
    {
        scanf("%d", &a[i]);
    }
}
void displayElements(int *sizeOfArray, int a[])
{
    printf("------------------------------------------\n");
    printf("The Elements in the Array are :");

    printf(" ");
    for (int i = 0; i < *sizeOfArray; i++)
    {
        printf("%d", a[i]);
        printf(" ");
    }
    printf("\n");
    printf("------------------------------------------\n");
}
int insertElements(int *sizeOfArray, int a[])
{
    int pos, element, flag = 0;
    printf("Enter The Element to be Inserted  : ");
    scanf("%d", &element);
    printf("Enter The Position  at which the Element has to be Inserted : ");
    scanf("%d", &pos);
    if ((pos == 0) || (pos > *sizeOfArray))
    {
        printf("Position out of bound...\n");
        flag = 1; //Check for out of range values , if user inputs incorrect value set flag to 1 and return to main function
    }
    else
    {
        *sizeOfArray += 1; //Increase the size of array so that new element can be inserted

        for (int i = *sizeOfArray - 2; i >= pos - 1; i--)
        {
            a[i + 1] = a[i];
        }
        a[pos - 1] = element;
    }
    return flag;
}
int deleteElements(int *sizeOfArray, int a[])
{
    int pos, flag = 0;
    ;
    printf("Enter The Position  at which the Element has to be Deleted : ");
    scanf("%d", &pos);
    if ((pos == 0) || (pos > *sizeOfArray))
    {
        printf("Position out of bound...\n");
        flag = 1;
    }
    else
    {
        for (int i = pos - 1; i > *sizeOfArray; i++)
        {
            a[i] = a[i + 1];
        }
        *sizeOfArray -= 1;
        //free the last element in array as it contains null value
    }
    return flag;
}

int input()
{
    int num;
    scanf("%d", &num);
    return num;
}
int continueOperation()
{
    int choice;
    printf("Do you want to continue the operation?\n");
    printf("Press 1 to continue or Press any button to exit\n");
    printf("Enter Choice!\t");
    scanf("%d", &choice);
    printf("------------------------------------------------\n");
    return choice;
}
