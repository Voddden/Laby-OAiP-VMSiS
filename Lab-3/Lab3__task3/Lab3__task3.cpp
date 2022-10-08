#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\ValidationLib\inputSN.h"
#include "..\ValidationLib\inputReal.h"

/*
��� ������ � ������� n, �� ���������� ������� ���������. 
���������� �������� ������ �, � ������� ������� ���� ������������� ��������, 
� ����� �������������. �������������� ������� �� ������������.
*/

void randArrDoub(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		arr[i] = double(rand() % 10) - rand() % 10;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == 0.0)
			++arr[i];
	}
}

void inputArrDoub(double arr[], int size) {
	char iHateC[] = "\narr[x] = ";
	system("cls");
	for (int i = 0; i < size; ++i) {
		iHateC[5] = i + 48;
		arr[i] = inputReal(iHateC);
		if (arr[i] == 0.0) {
			arr[i] = inputReal(iHateC);
			--i;
		}
	}
}

void outputArrDoub(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		printf("%-5.2lf\t", arr[i]);
}

void partialSort(double arr[], int size) {
	double temp = 0;
	for (int i = 0; i < size - 1; ++i) {
		for (int k = 0; k < size - 1 - i; ++k) {
			if (arr[k] < 0 && arr[k + 1] > 0) {
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
}

void main() 
{
	setlocale(LC_ALL, "ru");
	double A[100] = {};
	int n = inputSN("������� ����������� �������: ");
	while (n > 100) {
		n = inputSN("������� ����������� �������: ");
	}
	int choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\n");
	while (choice != 1 && choice != 2) {
		choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\n");
	}

	switch (choice) {
	case 1:
		inputArrDoub(A, n); break;
	case 2:
		randArrDoub(A, n);
	}

	printf("\n����������� ������:\n");
	outputArrDoub(A, n);
	// ����� �������� ����������
	partialSort(A, n);
	//
	printf("\n\n������ ����� ���������� (+�������� �����, -�������� ������):\n");
	outputArrDoub(A, n);
	printf("\n");
}