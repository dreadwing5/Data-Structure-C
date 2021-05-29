/*
12 Given a File of N employee records with a set K of Keys(4-digit) which
uniquely determine the records in file F. Assume that file F is maintained in
memory by a Hash Table(HT) of m memory locations with L as the set of
memory addresses (2-digit) of locations in HT. Let the keys in K and
addresses in L are Integers. Design and develop a Program in C that uses
Hash function H: K →L as H(K)=K mod m (remainder method), and
implement hashing technique to map a given key K to the address space L.
Resolve the collision (if any) using linear probing.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int F[MAX], HT[MAX], L;

void linear_probe(int k, int key)
{
	L = k % MAX;
	if (HT[L] == 0)
		HT[L] = key;
	else
		linear_probe(k + 1, key);
}

void display()
{
	int i;
	printf("\nHash Table:");
	for (i = 0; i < MAX; i++)
	{
		printf("\nHT [ %d ] ------> %d", i, HT[i]);
	}
	printf("\n");
}

int main()
{
	FILE *fp;
	int i;
	char buff[1000];
	fp = fopen("data.txt", "r");
	i = 0;
	while (fscanf(fp, "%d", &F[i]) != EOF)
	{
		fscanf(fp, "%[^\n]s ", buff);
		i++;
	}
	printf("\nThe number of records in the File are: %d", i);
	for (i = 0; i < MAX; i++)
	{
		L = F[i] % MAX;
		if (HT[L] == 0)
			HT[L] = F[i];
		else
			linear_probe(F[i] + 1, F[i]);
	}
	display();
	return (0);
}