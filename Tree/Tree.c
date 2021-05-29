#include "Queue.h"
#include "Stack.h"

void createTree()
{
    struct Tree *p, *t;
    int x;
    printf("Enter The Value of Root : ");
    scanf("%d", &x);
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enQueue(root);
    while (!isQueueEmpty())
    {
        p = deQueue(); //pop the item from queue and link it to lchild and rchild
        printf("Enter the left child of %d :  ", p->data);
        scanf("%d", &x);
        //Check for leaf node
        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enQueue(t); //Insert the address of lchild in queue
        }
        printf("Enter the right child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enQueue(t);
        }
    }
}

//Traversal using Recursion

void preOrder(struct Tree *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Tree *p)
{
    if (p)
    {

        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void postOrder(struct Tree *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

//Traversal Using Iteration
void IPreOrder(struct Tree *p)
{
    long int temp;

    while (p || !isStackEmpty())
    {
        if (p)
        {
            printf("%d ", p->data);
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            p = (struct Tree *)temp;
            p = p->rchild;
        }
    }
}

void IInOrder(struct Tree *p)
{
    long int temp;
    while (p || !isStackEmpty())
    {
        if (p)
        {

            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            p = (struct Tree *)temp;
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void IPostOrder(struct Tree *p)
{
    long int temp;
    while (p || !isStackEmpty())
    {
        if (p)
        {
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            if (temp > 0)
            {
                push(-temp);
                p = (struct Tree *)temp;
                p = p->rchild;
            }
            else
            {
                p = (struct Tree *)-temp;
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}

//Level Order Traversal
void lOrder(struct Tree *p)
{
    printf("%d ", p->data);
    enQueue(p);

    while (!isQueueEmpty())
    {
        p = deQueue();
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enQueue(p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enQueue(p->rchild);
        }
    }
}

int countNodes(struct Tree *p)
{
    if (p)
    {
        return countNodes(p->lchild) + countNodes(p->rchild) + 1;
    }
    return 0;
}
int countLeafNodes(struct Tree *p)
{
    int x, y;
    if (p)
    {
        x = countLeafNodes(p->lchild);
        y = countLeafNodes(p->rchild);
        if (!p->lchild && !p->rchild)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
}

int height(struct Tree *p)
{
    int x, y;
    x = y = 0;
    if (p)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return -1;
}

int main()
{
    createTree();
    printf("\nPreorder Traversal is : ");
    IPreOrder(root);
    printf("\n");
    printf("\nInorder Traversal is : ");
    IInOrder(root);
    printf("\n");
    printf("\nPostorder Traversal is : ");
    IPostOrder(root);
    printf("\n");
    printf("\nLevelorder Traversal is : ");
    lOrder(root);
    printf("\n");
    printf("\nNo. Of Nodes : %d ", countNodes(root));
    printf("\n");
    printf("\nHeight of Tree  : %d ", height(root));
    printf("\n");
    return 0;
}
