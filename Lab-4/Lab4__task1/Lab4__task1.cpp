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
	int S_mainDiag = 0; // ����� ��������� ������� ��������� ������� arr[][]
	int S_sideDiag = 0; // ����� ��������� �������� ��������� ������� arr[][]

	for (int i = 0; i < size; ++i)
		S_mainDiag += arr[i][i];
	for (int i = 0; i < size; ++i)
		S_sideDiag += arr[i][size - 1 - i];

	int* rowSums = (int*)calloc(size, sizeof(int)); // ������ ���� ��������� ������������� ����� ������� arr[][]
	int* colSums = (int*)calloc(size, sizeof(int)); // ������ ���� ��������� �������������� �������� ������� arr[][]

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			rowSums[i] += arr[i][j];
			colSums[i] += arr[j][i];
		}
	}

	// �������� �������� �� ��������� ���� �� ��������� ����� �����
	int tempRow = rowSums[0], tempCol = colSums[0];
	for (int i = 0; i < size; ++i) {
		if (rowSums[i] != tempRow)
			return false;
		if (colSums[i] != tempCol)
			return false;
	}

	// �������� �������� �� ��������� (����������� ������� ������������ ��������)
	for (int i = 0; i < size; ++i)
		if (rowSums[i] != colSums[i])
			return false;
	
	if (S_mainDiag == S_sideDiag == tempRow == tempCol)
		return true;
	else
		return false;
}

/*
��������� ������, ���������� ������ ����� ����� � ��������, 
���������� ���������� ���������, ���� ����� �����, 
���������� � ������ ������, ������ ������� � ������ �� ���� ������� ����������,
����� ������ � ���� �� �����. 
����������, �������� �� ������ ������ � �� n ����� � n �������� ���������� ���������.
*/

void main()
{
	setlocale(LC_ALL, "ru");
	int A[100][100] = {4, 5, 14, 11,
					   1, 15, 8, 10,
					   16, 2, 9, 7,
					   13, 12, 3, 6};
	int n = inputSN("������� ������� �������: ");
	while (n > 100) {
		n = inputSN("������� ����������� �������: ");
	}
	int choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\t3 - ����������\n");
	while (choice != 1 && choice != 2 && choice != 3) {
		choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\t3 - ����������\n");
	}

	
	switch (choice) {
	case 1:
		inputArr(A, n); break;
	case 2:
		randArr(A, n);
	case 3: break;
	}

	printf("\n������:\n");
	outputArr(A, n);

	printf("�������� �� ������ ����������? ");
	if (AisMagical(A, n))
		printf("��\n");
	else
		printf("���\n");
}