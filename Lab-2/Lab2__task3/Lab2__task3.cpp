#include <stdio.h>
#include <locale.h>
#include "..\ValidationLib\inputNatural.h";
/*
Проверить являются ли числа P и Q взаимнопростыми
*/
int nod(int m, int n)
{
	return n ? nod(n, m % n) : m; // алгоритм Евклида
}

void main()
{
	setlocale(LC_ALL, "ru");
	int P = inputNatural("Enter P: ");
	int Q = inputNatural("Enter Q: ");

	if (nod(P, Q) == 1)
		printf("%d и %d взаимнопросты\n", P, Q);
	else
		printf("%d и %d НЕвзаимнопросты\n", P, Q);
}