#include <stdio.h>
#include <locale.h>
#include "..\ValidationLib\inputNatural.h";
/*
��������� �������� �� ����� P � Q ���������������
*/
int nod(int m, int n)
{
	return n ? nod(n, m % n) : m; // �������� �������
}

void main()
{
	setlocale(LC_ALL, "ru");
	int P = inputNatural("Enter P: ");
	int Q = inputNatural("Enter Q: ");

	if (nod(P, Q) == 1)
		printf("%d � %d �������������\n", P, Q);
	else
		printf("%d � %d ���������������\n", P, Q);
}