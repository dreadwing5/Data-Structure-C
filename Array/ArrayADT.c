#include <stdio.h>
#include <stdlib.h>

//Create a structure to store Array
struct Array
{
    int *A; //Dynamically store elements in the array
    int sizeOfArray;
    int length;
};

void DisplayArray(struct Array *arr)
{
    printf("The Array is : ");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
    /* printf("%ptr",&arr->A); Address inside function  */
}

void AppendArray(struct Array *arr)
{
    if (arr->length < arr->sizeOfArray)
    {
        int element;
        printf("Enter The Element To Be Appended : ");
        scanf("%d", &element);
        arr->A[arr->length++] = element;
    }
}

void InsertElement(struct Array *arr)
{
    int pos;
    int element;
    printf("Enter The Element To Be Inserted : ");
    scanf("%d", &element);
    printf("Enter The Position : ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > arr->length)
    {
        return;
    }
    arr->length++;
    for (int i = arr->length; i > pos - 1; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[pos - 1] = element;
}

void DeleteElements(struct Array *arr)
{

    int pos;
    printf("Enter The Position At Which the Element has to be Deleted: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > arr->length)
    {
        return;
    }
    for (int i = pos - 1; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

void swap(int *a,int *b){

    int temp =*a;
    *a=*b;
    *b=temp;
}

void ReverseArray(struct Array *arr)

{
    int i,j;
    for (i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{

    struct Array *arr; //Structure Declerartion
    int choice;
    printf("Enter The Size Of Array: ");
    scanf("%d", &arr->sizeOfArray);
    arr->A = (int *)malloc(arr->sizeOfArray * sizeof(int)); //This will generate an array in the heaps
    arr->length = 0;
    printf("Enter The Number of Elements To Be Stored: ");
    scanf("%d", &arr->length);
    //Fill the elements in the array
    printf("Enter The Elements Of The Array : ");
    for (int i = 0; i < arr->length; i++)
    {
        scanf("%d", &arr->A[i]);
    }
    do
    {
        /* printf("%ptr ",&arr->A); //Address inside main */
        printf("\nEnter Array Operation : \n");
        printf("1.Display Array\n");
        printf("2.Append Element\n");
        printf("3.Insert Elements\n");
        printf("4.Delete Elements\n");
        printf("5.Reverse Array\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            DisplayArray(arr);
            break;
        case 2:
            AppendArray(arr);
            break;
        case 3:
            InsertElement(arr);
            break;
        case 4:
            DeleteElements(arr);
            break;
        case 5 :
            ReverseArray(arr);
            break;

        default:
            return 0;
        }
    } while (choice != 6);
    free(arr->A);
    return 0;
}
