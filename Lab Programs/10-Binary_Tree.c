#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

//Function to Insert Element
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
    int x, y;
    x = y = 0;
    if (p)
    {
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }
    return -1;
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

//Traversal
void inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void preOrder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    int ch, key, n;

    while (1)
    {
        printf("\n1: Insert \n2: Delete\n3: Search\n4: Inorder Traversal\n5: PreOrder Traversal\n6: PostOrder Traversal\n7:Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter The No Of Elements To Be Inserted : ");
            scanf("%d", &n);
            printf("\nEnter The Elements To Be Inserted : ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &key);
                insert(key);
            }
            break;
        case 2:
            printf("Enter The Element To Be Deleted : ");
            scanf("%d", &key);
            Delete(root, key);
            break;
        case 3:
            printf("Enter The Element To Be Searched : ");
            scanf("%d", &key);
            struct Node *foundKey = Search(key);
            if (foundKey)
            {
                printf("\nKey was found at Address %ptr \n", foundKey);
            }
            else
            {
                printf("\nCouldn't find the Key!\n");
            }
            break;
        case 4:
            printf("The InOrder Traversal is : ");
            inOrder(root);
            break;
        case 5:
            printf("The PreOrder Traversal is : ");
            preOrder(root);
            break;
        case 6:
            printf("The PostOrder Traversal is : ");
            postOrder(root);
            break;
        case 7:
            return 0;

        default:
            printf("\nInvalid Choice !!!\n");
        }
    }
    return 0;
}
