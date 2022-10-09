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

	for (int h = 0; h < size; ++h) {
		for (int i = 0; i < size; ++i) {
			rowSums[h] += arr[h][i];
			colSums[h] += arr[i][h];
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
	
	bool wtf = (S_mainDiag == S_sideDiag) == (tempRow == tempCol);

	if (wtf)
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
	int A[100][100] = {};
	int n = inputSN("������� ������� ��������: ");
	while (n > 100) {
		n = inputSN("������� ������� ��������: ");
	}

	//// ����������� ������� � �������� ����:
	A[0][0] = 4; A[0][1] = 5; A[0][2] = 14; A[0][3] = 11;
	A[1][0] = 1; A[1][1] = 15; A[1][2] = 8; A[1][3] = 10;
	A[2][0] = 16; A[2][1] = 2; A[2][2] = 9; A[2][3] = 7;
	A[3][0] = 13; A[3][1] = 12; A[3][2] = 3; A[3][3] = 6;
	//

	int choice = inputSN("---��������� ������� � ���������� - 1\t���������� ���������� - 2\t�������� �� ��������� - 3\n");
	while (choice != 1 && choice != 2 && choice != 3) {
		choice = inputSN("---��������� ������� � ���������� - 1\t���������� ���������� - 2\t�������� �� ��������� - 3\n");
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

	printf("�������� �� ������� ����������? ");
	if (AisMagical(A, n))
		printf("��\n");
	else
		printf("���\n");
}