#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\ValidationLib\inputReal.h"
#include "..\ValidationLib\inputSN.h"

/* Вариант-1
В одномерном массиве, состоящем из n вещественных элементов, вычислить:
- сумму отрицательных элементов массива;
- произведение элементов массива, расположенных между максимальным и минимальным элементами.
*/

void randArrDoub(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		arr[i] = double(rand() % 10) - rand() % 10;
}

void inputArrDoub(double arr[], int size) {
	char iHateC[] = "\narr[x] = ";
	system("cls");
	for (int i = 0; i < size; ++i) {
		iHateC[5] = i + 48;
		arr[i] = inputReal(iHateC);
	}
}

void outputArrDoub(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		printf("%-5.3lf\t", arr[i]);
}

double sumOfNegativeElements(double arr[], int size) {
	double sum = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0)
			sum += arr[i];
	}
	return sum;
}

int ABS(int num) {
	if (num < 0)
		num *= -1;
	return num;
}

double composition(double arr[], int size) {
	double max = arr[0];
	int indexMax = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i];
			indexMax = i;
		}
	}
	double min = arr[0];
	int indexMin = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < min) {
			min = arr[i];
			indexMin = i;
		}
	}
	double c = 1;
	if (indexMax == indexMin || ABS(indexMax - indexMin) == 1) {
		c = 0;
	}
	else if (indexMin < indexMax) { // min �����, max ������ (�� �����������)
		for (int i = indexMin + 1; i < indexMax; ++i)
			c *= arr[i];
	}
	else if (indexMin > indexMax) { // min ������, max ����� (�� ��������) 
		for (int i = indexMax + 1; i < indexMin; ++i)
			c *= arr[i];
	}

	return c;
}

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	double arr[100] = {};

	int size = inputSN("������� ����������� �������: ");
	while (size > 100) {
		size = inputSN("������� ����������� �������: ");
	}
	int choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\n");
	while (choice != 1 && choice != 2) {
		choice = inputSN("---��������� ������ � ���������� - 1\t���������� ���������� - 2\n");
	}

	switch (choice) {
	case 1:
		inputArrDoub(arr, size); break;
	case 2:
		randArrDoub(arr, size);
	}

	printf("\n������:\n");
	outputArrDoub(arr, size);

	printf("\n����� ������������� ��������� �������: %lf\n", sumOfNegativeElements(arr, size));
	printf("������������ ��������� �������, ������������� ����� ������������ � ����������� ����������: %lf\n", composition(arr, size));
}