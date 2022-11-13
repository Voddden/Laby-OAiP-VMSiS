#include "../../ValidationLib/Validation.h"

int** allocation(int m, int n)
{
	int** mas;
	mas = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		mas[i] = (int*)malloc(n * sizeof(int)); //*(mas + i)
	}
	return mas;
}

void inputArr(int** arr, int m, int n) {
	char iHateC[] = "arr[.][.] = ";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			iHateC[4] = i + 48; 
			iHateC[7] = j + 48;
			arr[i][j] = inputInteger(iHateC);
		}
	}
}

void randArr(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = rand() % 10 - rand() % 10;
		}
	}
}

void outputArr(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapRows(int* a, int* b, int n) {
	int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		temp[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}
	for (int i = 0; i < n; ++i) {
		b[i] = temp[i];
	}

}

void main() 
{
	int arr1[3][4] = {8, -1, 0, -4,
					  2,  3, 2, -1,
					  -3, 1, 0,  9 };

	int* a;
	int* b;
	int n = 4;

	int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		temp[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}
	for (int i = 0; i < n; ++i) {
		b[i] = temp[i];
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
}