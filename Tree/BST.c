#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    struct Node *t = root;
    struct Node *p, *r;

    //Check if It's an empty tree

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        printf("\nRoot Node Created!\n");
    }
    else
    {
        while (t)
        {
            r = t; //r is a tailing pointer
            if (key < t->data)
            {
                t = t->lchild;
            }
            else if (key > t->data)
            {
                t = t->rchild;
            }
            //If Key already exist
            else
            {
                return;
            }
        }
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        if (key < r->data)
            r->lchild = p;
        else
            r->rchild = p;
        // printf("\n%d added Successfully\n", key);
    }
}

void inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

//Binary Search

struct Node *Search(int key)
{

    struct Node *p = root;

    while (p)
    {
        if (key < p->data)
        {
            p = p->lchild;
        }
        else if (key > p->data)
        {
            p = p->rchild;
        }
        else
        {

            return p;
        }
    }

    return NULL;
}

int Height(struct Node *p)
{
    int x;
    int y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
struct Node *inOrderPre(struct Node *p)
{
    while (p && p->rchild)
    {
        p = p->rchild;
    }
    return p;
}
struct Node *inOrderSucc(struct Node *p)
{
    while (p && p->lchild)
    {
        p = p->lchild;
    }
    return p;
}

//Recursive Delete
struct Node *Delete(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        return NULL;
    }
    if (!p->lchild && !p->rchild)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    //Search for the key
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    //Key was found
    else
    {
        //Check for Height
        if (Height(p->lchild) < Height(p->rchild))
        {
            t = inOrderPre(p->lchild);
            p->data = t->data;
            p->lchild = Delete(p->lchild, t->data);
        }
        else
        {
            if (p->rchild)
            {
                t = inOrderSucc(p->rchild);
                p->data = t->data;
                p->rchild = Delete(p->rchild, t->data);
            }
            else
            {
                t = inOrderSucc(p->lchild);
                p->data = t->data;
                p->lchild = Delete(p->lchild, t->data);
            }
        }
    }
    return p;
}

int main()
{
    insert(9);
    insert(15);
    insert(5);
    insert(20);
    insert(16);
    insert(8);
    insert(12);
    insert(3);
    insert(6);
    Delete(root, 20);
    inOrder(root);
    struct Node *foundKey = Search(8);
    if (foundKey)
    {
        printf("\nKey was found at Address %ptr \n", foundKey);
    }
    else
    {
        printf("\nCouldn't find the Key!\n");
    }

    return 0;
}