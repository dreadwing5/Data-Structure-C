#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next; //Self Refrential Structure
} *first = NULL, *second = NULL, *third = NULL;

//Creating A Linked list using last
void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t; //Lec 173
    }
}
void create2(int A[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void recursiveDisplay(struct Node *P)
{
    if (P != NULL)
    {
        printf("%d ", P->data);
        recursiveDisplay(P->next);
    }
}
void reverseDisplay(struct Node *P)
{
    if (P != NULL)
    {
        reverseDisplay(P->next);
        printf("%d ", P->data);
    }
}
int countNode(struct Node *P)
{
    static int count = 0;
    while (P != NULL)
    {
        P = P->next;
        count++;
    }
    return count;
}

int Sum(struct Node *P)
{
    int sum;

    if (P != NULL)
    {
        return Sum(P->next) + P->data;
    }
    else
    {
        return 0;
    }
    return sum;
}

void display(struct Node *P)
{
    while (P != NULL)
    {
        printf("%d ", P->data);
        P = P->next; // Move to the next element
    }
    printf("\n");
}
int maxElement(struct Node *P)
{
    int max = INT32_MIN;
    while (P != NULL)
    {
        if (max < P->data)
        {
            max = P->data;
        }
        P = P->next;
    }
    return max;
}
//Max Element in Linked List using Recursion
int rmax(struct Node *P)
{
    int x = 0;
    if (P == 0)
    {
        return INT32_MIN;
    }
    x = rmax(P->next);
    return x > P->data ? x : P->data;
}
struct Node *search(struct Node *P, int key)
{
    while (P != NULL)
    {
        if (P->data == key)
        {

            return P;
        }
        P = P->next;
    }
    return NULL;
}

//FUnction to Insert an Element in a Linked List
void insertElement(struct Node *P, int index, int x, int count)
{
    struct Node *t;
    //Adding element before the first element
    if (index < 0 || index > count)
    {
        printf("Index Out of Range!\n");
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {

        t->next = first; //Point to the first element in the array
        first = t;
    }
    //Adding at any index other than 0
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            P = P->next; //Move to the next Node
        }
        t->next = P->next;
        P->next = t;
    }
}
void sortedInsert(struct Node *P, int x)
{
    struct Node *q, *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (P && P->data < x)
        {
            q = P;
            P = P->next;
        }
        //check if we element  to be added is at the beginning
        if (P == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int deleteElement(struct Node *P, int pos, int count)
{
    if (pos < 1 || pos > count)
    {
        return -1;
    }
    int x = -1;
    struct Node *q; //Tailing Pointer
    q = first;
    if (pos == 1)
    {
        x = first->data;
        first = P->next;
        free(P);
        return x;
    }
    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            q = P;
            P = P->next;
        }
        int x = P->data;
        q->next = P->next;
        free(P); //Delete P
        return x;
    }
}
bool checkSorted(struct Node *P)
{
    int x = INT32_MIN;
    while (P != NULL)
    {

        if (x > P->data)
        {
            return false;
        }
        x = P->data;
        P = P->next;
    }
    return true;
}
void findDuplicates(struct Node *P, int max)
{
    struct Node *q; //Sliding Pointer
    int *H;
    H = (int *)calloc(max + 1, sizeof(int)); //Create a Hashtable of size max
    q = first;

    while (q != NULL)
    {
        if (H[q->data] == 1)
        {
            //Delete Node
            P->next = q->next;
            free(q);
            q = P->next;
        }
        else
        {
            H[q->data] = 1;
            //Move Both Pointer
            P = q;
            q = q->next;
        }
    }
    /*   for (int i = 0; i < max + 1; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n"); */
}
void reverseElements(struct Node *P, int count)
{
    int *A, i = 0;
    A = (int *)malloc(count * sizeof(int));
    while (P != NULL)
    {
        //Copy the element to array
        A[i++] = P->data;
        P = P->next;
    }
    P = first;
    i--;
    while (P != NULL)
    {
        P->data = A[i--];
        P = P->next;
    }
}
//Reverse of Linked List using Sliding Pointer
void reverseLinks(struct Node *P)
{
    struct Node *q, *r;
    q = NULL;
    r = NULL;
    while (P != NULL)
    {
        r = q;
        q = P;
        P = P->next;
        q->next = r;
    }
    first = q;
}
void rReverseLinks(struct Node *q, struct Node *P)
{
    if (P != NULL)
    {
        rReverseLinks(P, P->next);
        P->next = q;
    }
    else
    {
        first = q;
    }
}

//Join two unsorted/sorted list
void concatenateList(struct Node *first, struct Node *second)
{
    third = first;
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = second;
    second = NULL;
}
//Function To Merge two sorted list into a a single sorted list
void mergeList(struct Node *first, struct Node *second)
{
    struct Node *last;
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        second->next = NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
}
bool isLoop(struct Node *P)
{
    struct Node *q;
    q = first;
    do
    {
        P = P->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (P && q && q != P);
    return P == q ? true : false;
}

int main()
{
    int A[] = {3, 6, 9, 10, 11};
    int n = sizeof(A) / sizeof(int);
    create(A, n);
    struct Node *t1, *t2;
    t1 = first->next->next;             //Point to third element in Array
    t2 = first->next->next->next->next; //Point to the last element in array
    t2->next = t1;
    //LOOP
    /* int B[] = {4, 8, 10};
    int r = sizeof(B) / sizeof(int);*/

    printf("%s", isLoop(first) ? "true " : "false ");

    /* create2(B, r);
    display(first);
    display(second);
    concatenateList(first, second);
    mergeList(first, second);
    display(third); */

    /* printf("\nDisplaying Linked List using Recursion : \n");
    recursiveDisplay(first);
    printf("\nThe Reverse Using Recursion : \n");
    reverseDisplay(first);
    int count = countNode(first);
    printf("\nLength of The Linked List = %d", count);
    int sum = Sum(first);
    printf("\nThe Sum is : %d\n", sum);
    int max = rmax(first);
    printf("The Maximum Element is : %d\n", max);
    struct Node *m = search(first, 3);
    if (m != NULL)
    {
        printf("Element Found at Addreess %p\n", m);
    }
    else
    {
        printf("Element Not Found!");
    }
    if (checkSorted(first))
    {
        printf("List is sorted!\n");
    }
    else
    {
        printf("List is not sorted!\n");
    }
    rReverseLinks(NULL, first);
    display(first); */

    return 0;
}