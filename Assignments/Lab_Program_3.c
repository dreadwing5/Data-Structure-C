#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *A;
};
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {

        st->top++;
        st->A[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        x = st->A[st->top];
        st->top--;
    }
    return x;
}
void display(struct Stack st)
{
    while (st.top != -1)
    {
        printf("%d ", st.A[st.top]);
        st.top--;
    }
}
void isPalindrome(struct Stack *st)
{
    int n, digit, x, flag = 1;
    printf("Enter The Number Of Digits : ");
    scanf("%d", &n);
    printf("Enter The Digits : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &digit);
        push(st, digit);
    }
    int i = 0;
    while (st->top != -1)
    {
        x = pop(st);
        if (x != st->A[i])
        {
            flag = 0;
        }
        i++;
    }
    if (flag)
    {
        printf("It is Palindrome!");
    }
    else
    {
        printf("It is not a Palindrome!");
    }
}

int main()
{
    int choice, x = 0;
    struct Stack st;
    printf("Enter The Size of the Stack : ");
    scanf("%d", &st.size);
    st.A = (int *)malloc(st.size * sizeof(int));
    st.top = -1;
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.Palindrome\n\t 5.EXIT\n\t");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter The Element To Be Inserted: ");
            scanf("%d", &x);
            push(&st, x);
            break;
        }
        case 2:
        {
            pop(&st);
            break;
        }
        case 3:
        {
            display(st);
            break;
        }
        case 4:
        {
            isPalindrome(&st);
            break;
        }
        case 5:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 5);
    return 0;
}