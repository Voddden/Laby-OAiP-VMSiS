#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\..\ValidationLib\inputNatural.h"

void inputArr(int arr[][], int m, int n) {
	system("cls");
	char iHateC[] = "\narr[.][.] = ";

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			iHateC[8] = j + 48;
			arr[i][j] = inputNatural(iHateC);
		}
		iHateC[5] = i + 1 + 48;
	}
}

void outputArr(int arr[][], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			printf("%-d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void randArr(int arr[][], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			arr[i][j] = rand() % 10;
		}
	}
}

int** allocation(int m, int n)
{
	int** mas;
	mas = (int**)calloc(m, sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		mas[i] = (int*)calloc(n, sizeof(int)); //*(mas + i)
	}
	return mas;
}

/* В-12
1) Упорядочить строки целочисленной прямоугольной матрицы
по возрастанию количества одинаковых элементов в каждой строке.
2) Найти номер первого из столбцов, не содержащих ни одного отрицательного элемента.
*/

void main()
{
	setlocale(LC_ALL, "ru");
	//int A[100][100] = {};

	printf("Матрица m x n\n");

	int m = inputNatural("m = ");
	//while (m > 100) {
	//	m = inputNatural("Error\nm = ");
	//}
	int n = inputNatural("n = ");
	//while (n > 100) {
	//	n = inputNatural("Error\nn = ");
	//}

	int** A = allocation(m, n);

	int choice = inputNatural("---Заполнить квадрат с клавиатуры - 1\tслучайными значениями - 2\n");
	while (choice != 1 && choice != 2) {
		choice = inputNatural("Error\n---Заполнить квадрат с клавиатуры - 1\tслучайными значениями - 2\n");
	}

	switch (choice) {
	case 1:
		inputArr(A, n); break;
	case 2:
		randArr(A, n);
	}

	printf("\nМатрица:\n");
	outputArr(A, n);

	printf("Упорядоченная матрица:\n");
	outputArr(A, n);
}