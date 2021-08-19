#include <stdio.h>
#include <stdlib.h>

struct HashTable
{
    int key;
    int flag; //Keeping count of probed data
};
struct HashTable *HT; // Declaring Hashtable as global variable;
int size;

int Hash(int key)
{
    return key % size;
}

int linearProbe(int key)
{
    int i = 0;
    while (HT[(key + i) % 10].key != 0)
    {
        i++;
    }
    return (key + i) % 10;
}
void insert(int key)
{
    int index;
    index = Hash(key);
    if (HT[index].key == 0)
    {
        HT[index].key = key;
    }
    else
    {
        index = linearProbe(key);
        HT[index].key = key;
        HT[index].flag = 1; //Index is linearly probed
    }
}
int search(int key)
{
    int index, i = 0;
    int searchedIndex = (index + i) % size;
    ;
    index = Hash(key);
    while (HT[searchedIndex].key != key)
    {
        searchedIndex = (index + i) % size;
        if (HT[searchedIndex].key == 0)
        {
            return searchedIndex; //Unsuccessful search
        }
        i++;
    }
    return searchedIndex;
}
void rehash(int index)
{

    HT[index].key = 0;
    HT[index].flag = 0;
    int i = 0, temp;
    while (i < size)
    {
        if (HT[i].key != 0)
        {
            temp = HT[i].key;
            HT[i].key = 0;
            HT[i].flag = 0;
            insert(temp);
        }
        i++;
    }
}
int delete (int key)
{

    int temp;
    int index = search(key);
    if (HT[index].key == 0)
    {
        return 0;
    }

    if (HT[index + 1].flag == 0)
    {
        temp = HT[index].key;
        HT[index].key = 0;
        HT[index].flag = 0;
    }
    else
    {
        rehash(index);
        temp = key;
    }

    return temp;
}
void display()
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", HT[i].key);
        printf("%d ", HT[i].flag);
        printf("\n");
    }
}

int main()
{
    int n, dk, sk;
    // printf("Enter The Number of Keys : ");
    // scanf("%d", &n);
    size = 10;
    HT = (struct HashTable *)malloc(size * sizeof(struct HashTable)); //Creating a dynamic array of structure
    for (int i = 0; i < size; i++)
    {
        HT[i].key = 0;
        HT[i].flag = 0;
    }
    insert(30);
    insert(40);
    insert(50);
    insert(80);
    insert(44);
    insert(85);
    insert(95);
    insert(10);
    display();
    printf("Enter The Element to Be Searched: ");
    scanf("%d", &sk);
    int foundKey = HT[search(sk)].key;
    if (foundKey)
    {
        printf("%d was found!\n", foundKey);
    }
    else
    {
        printf("Key was not found!\n");
    }
    printf("Enter The Element to Be Deleted : \n");
    scanf("%d", &dk);

    int deletedKey = delete (dk);
    if (deletedKey)
    {
        printf("%d was deleted successfully!\n", deletedKey);
        display();
    }
    else
    {
        printf("%d was not found!\n", dk);
    }
}
