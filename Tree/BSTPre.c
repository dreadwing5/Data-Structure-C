//Generating a Binary Tree From PreOrder Traversal

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

struct Stack
{
    struct Node *sdata; //Stack Data , Stores the address of each node. It's in long int format beacuse we need to store negative address.
    struct Stack *next;
} *top = NULL;

void push(struct Node *x)
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    if (top == NULL)
    {
        t->sdata = x;
        t->next = NULL;
        top = t;
    }
    else
    {
        t->sdata = x;
        t->next = top;
        top = t;
    }
}
//Returns the address of a node of tree
struct Node *pop()
{
    struct Node *x;
    struct Stack *t;
    x = top->sdata;
    t = top->next;
    free(top);
    top = t;
    return x; //Returns the address of Node
}

struct Node *stackTop()
{
    return top->sdata;
}

int isEmpty()
{
    return top == NULL;
}

void createPre(int pre[], int n)
{
    struct Node *t, *p;
    int i = 0;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < (isEmpty() ? INT32_MAX : stackTop()->data))
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = pop();
            }
        }
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

int main()
{

    int A[] = {30, 20, 10, 15, 25, 40, 50, 45};
    createPre(A, sizeof(A) / sizeof(int));
    inorder(root);
}