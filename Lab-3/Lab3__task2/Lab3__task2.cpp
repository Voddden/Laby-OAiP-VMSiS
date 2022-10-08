#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\ValidationLib\inputSN.h"

/*� ������� �� n ��������� ������� ��� ������ ��������*/

void randArrInt(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 9 + 1;
}

void inputArrInt(int arr[], int size) {
	char iHateC[] = "arr[x] = ";
	system("cls");
	for (int i = 0; i < size; ++i) {
		iHateC[4] = i + 48;
		arr[i] = inputSN(iHateC);
	}
}

void outputArrInt(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		printf("%-d\t", arr[i]);
}

void main()
{
	setlocale(LC_ALL, "ru");
	int arr[100] = {};
	int n = inputSN("������� ����������� �������: ");
	while (n > 100) {
		n = inputSN("������� ����������� �������: ");
	}
	int choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\n");
	while (choice != 1 && choice != 2) {
		choice = inputSN("��������� ������ � ���������� - 1\t���������� ���������� - 2\n");
	}

	switch (choice) {
	case 1:
		inputArrInt(arr, n); break;
	case 2:
		randArrInt(arr, n);
	}
	
	printf("����������� ������:\n");
	outputArrInt(arr, n);

	// �����:
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2 == 0) {
			for (int k = i; k < n + 1; ++k) {
				arr[k] = arr[k + 1];
			}
			--i; 
			--n; // ����������� ���-�� ��������������� ��������� �������
		} 
	}
	
	printf("\n����� �������� ���� ��������� � ������ ���������:\n");
	outputArrInt(arr, n);
}