#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\ValidationLib\inputSN.h"

void inputArr(int arr[][100], int size) {
	system("cls");
	char iHateC[] = "\narr[0][.] = ";
	
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			iHateC[8] = j + 48;
			arr[i][j] = inputSN(iHateC);
		}
		iHateC[5] = i + 1 + 48;
	}
}

void outputArr(int arr[][100], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			printf("%-d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void randArr(int arr[][100], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			arr[i][j] = rand() % 10;
		}
	}
}

bool AisMagical(int arr[][100], int size) {
	int S_mainDiag = 0; // сумма элементов главной диагонали массива arr[][]
	int S_sideDiag = 0; // сумма элементов побочной диагонали массива arr[][]

	for (int i = 0; i < size; ++i)
		S_mainDiag += arr[i][i];
	for (int i = 0; i < size; ++i)
		S_sideDiag += arr[i][size - 1 - i];

	int* rowSums = (int*)calloc(size, sizeof(int)); // массив сумм элементов соответвующих строк массива arr[][]
	int* colSums = (int*)calloc(size, sizeof(int)); // массив сумм элементов соответсвующих столбцов массива arr[][]

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			rowSums[i] += arr[i][j];
			colSums[i] += arr[j][i];
		}
	}

	// проверка массивов на равенство всех их элементов между собой
	int tempRow = rowSums[0], tempCol = colSums[0];
	for (int i = 0; i < size; ++i) {
		if (rowSums[i] != tempRow)
			return false;
		if (colSums[i] != tempCol)
			return false;
	}

	// проверка массивов на равенство (необходимое условие магическости квадрата)
	for (int i = 0; i < size; ++i)
		if (rowSums[i] != colSums[i])
			return false;
	
	if (S_mainDiag == S_sideDiag == tempRow == tempCol)
		return true;
	else
		return false;
}

/*
Двумерный массив, содержащий равное число строк и столбцов, 
называется магическим квадратом, если суммы чисел, 
записанных в каждой строке, каждом столбце и каждой из двух больших диагоналей,
равны одному и тому же числу. 
Определить, является ли данный массив А из n строк и n столбцов магическим квадратом.
*/

void main()
{
	setlocale(LC_ALL, "ru");
	int A[100][100] = {4, 5, 14, 11,
					   1, 15, 8, 10,
					   16, 2, 9, 7,
					   13, 12, 3, 6};
	int n = inputSN("Введите порядок массива: ");
	while (n > 100) {
		n = inputSN("Введите размерность массива: ");
	}
	int choice = inputSN("---Заполнить массив с клавиатуры - 1\tслучайными значениями - 2\t3 - пропустить\n");
	while (choice != 1 && choice != 2 && choice != 3) {
		choice = inputSN("---Заполнить массив с клавиатуры - 1\tслучайными значениями - 2\t3 - пропустить\n");
	}

	
	switch (choice) {
	case 1:
		inputArr(A, n); break;
	case 2:
		randArr(A, n);
	case 3: break;
	}

	printf("\nМассив:\n");
	outputArr(A, n);

	printf("Является ли массив магическим? ");
	if (AisMagical(A, n))
		printf("да\n");
	else
		printf("нет\n");
}