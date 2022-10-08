#include <stdio.h>
#include "..\ValidationLib\inputSN.h";
/*
—оставить алгоритм,  определ€ющий  количество способов,  
какими   задуманное число n>1 можно представить 
в виде  суммы  n=i^3+j^3,  счита€, что перестановка слагаемых 
нового способа не даЄт.
*/

void main() 
{
	int n = inputSN("Enter n>1: ");
	while (n <= 1) {
		printf("Wrong input\n");
		n = inputSN("Enter n>1: ");
	}

	int k = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ( i*i*i + j*j*j == n) k++;
	printf("Number of ways = %d", k);
}