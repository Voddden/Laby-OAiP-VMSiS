#include "../../ValidationLib/Validation.h"

int** allocation(int m, int n)
{
	int** mas;
	mas = (int**)calloc(m, sizeof(int*));
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

}

void outputArr(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void main() {

	int m = 2, n = 3;
	int** arr = allocation(m, n);
	//outputArr(arr, m, n);
	inputArr(arr, m, n);
	outputArr(arr, m, n);
}