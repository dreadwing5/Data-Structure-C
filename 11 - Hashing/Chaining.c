#include "Chains.h"

int findIndex(int key)
{
    return key % 10;
}
void insert(int key)
{
    int index;
    index = findIndex(key);
    sortedInsert(index, key);
}

NODE search(int key)
{
    NODE P;
    int index = findIndex(key);
    P = HT[index];
    while (P)
    {
        if (P->data == key)
        {
            return P;
        }
        else
        {
            P = P->next;
        }
    }

    return NULL;
}

NODE delete (int key)
{
    NODE P, q, deletedKey;
    q = deletedKey = NULL;
    int index = findIndex(key);
    P = HT[index];
    while (P && P->data != key)
    {

        q = P;
        P = P->next;
    }
    if (P != NULL)
    {
        if (key == P->data)
        {

            deletedKey = P;
            if (P->next == NULL)
            {
                //Key is present at front node and it's the only node
                if (P == HT[index])
                {
                    HT[index] = NULL;
                }
                else //Key is present at last node
                {
                    q->next = NULL;
                }
            }
            else
            {

                //key is present betweent two nodes
                q->next = P->next;
            }
        }
    }

    free(P);
    return deletedKey;
}

void display(NODE *Hash)
{
    NODE P;
    for (int i = 0; i < 10; i++)
    {
        P = Hash[i];
        while (P)
        {
            printf("%d ", P->data);
            P = P->next;
        }
        if (P == NULL && P == Hash[i])
        {
            printf("NULL");
        }

        printf("\n");
    }
}

int main()
{
    int sk, dk;
    HT = (NODE *)malloc(10 * sizeof(struct Node *)); // Creating an array of pointer

    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    insert(10);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(16);
    insert(36);
    insert(35);
    insert(25);
    insert(5);
    display(HT);
    printf("Enter The Key to Be Searched : ");
    scanf("%d", &sk);
    NODE foundKey = search(sk);
    if (foundKey)
    {
        printf("%d was found!", foundKey->data);
    }
    else
    {
        printf("Key was not found!");
    }
    printf("\nEnter The Key to Be Deleted : ");
    scanf("%d", &dk);
    NODE deletedKey = delete (dk);
    if (deletedKey)
    {
        printf("%d was deleted!\n\n", deletedKey->data);
        display(HT);
    }
    else
    {
        printf("%d was not found!", dk);
    }
    return 0;
}