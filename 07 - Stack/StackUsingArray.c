#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        //Push Element
        st->top++;
        st->A[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        x = st->A[st->top--];
    }
    return x;
}
void display(struct Stack st)
{
    while (st.top != -1)
    {
        printf("%d ", st.A[st.top--]);
    }
    printf("\n");
}
bool isFull(struct Stack st)
{
    return (st.top == st.size - 1);
}
bool isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return true;
    }
    return false;
}
int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
    {
        printf("Invalid position!\n");
    }
    else
    {
        x = st.A[st.top - pos + 1];
    }
    return x;
}

int main()
{
    struct Stack st;
    int choice, x, index;
    printf("Enter the size of stack: ");
    scanf("%d", &st.size);
    st.A = (int *)malloc(st.size * sizeof(int));
    st.top = -1;
    printf("1.Push\n2.Pop\n3.isFull\n4.isEmpty\n5.Peek\n6.Display\n7.Exit\n");

    do
    {
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter The Element To Be Pushed: ");
            scanf("%d", &x);
            push(&st, x);
            break;
        case 2:
            printf("%d is popped!\n", pop(&st));
            break;

        case 3:
            printf("%s", isFull(st) ? "true " : "false ");
            break;
        case 4:
            printf("%s", isEmpty(st) ? "true " : "false ");
            break;
        case 5:
            printf("Enter The Index: ");
            scanf("%d", &index);
            printf("%d\n", st.A[peek(st, index + 1)]);
            break;
        case 6:
            display(st);
            break;
        case 7:
            printf("Exiting Program...");
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    } while (choice != 7);

    return 0;
}
