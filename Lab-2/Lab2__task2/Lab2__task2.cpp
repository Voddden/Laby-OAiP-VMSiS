#include <stdio.h>
#include "..\ValidationLib\inputNatural.h";
/*
��������� ��������,  ������������  ���������� ��������,  
������   ���������� ����� n>1 ����� ����������� 
� ����  �����  n=i^3+j^3,  ������, ��� ������������ ��������� 
������ ������� �� ���.
*/

void main() 
{
	int n = inputNatural("Enter n>1: ");
	while (n <= 1) {
		printf("Wrong input\n");
		n = inputNatural("Enter n>1: ");
	}

	int k = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ( i*i*i + j*j*j == n) k++;
	printf("Number of ways = %d", k);
}