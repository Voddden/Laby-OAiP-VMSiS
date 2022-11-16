#include <stdlib.h>
#include <stdio.h>

void shift(int* arr, int size, int Ineedless) {
	for (int i = Ineedless; i < size; ++i) {
		arr[i] = arr[i + 1];
	}
}

void deleteNull(int* arr, int& size) {
	int newSize = size;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == 0) {
			shift(arr, size, i);
			--newSize;
			--i;
		}
	}
	realloc(arr, newSize);
	size = newSize;
}

void main()
{
	int size = 12;
	int* arr = (int*)malloc(size * sizeof(int));


	for (int i = 0; i < size; ++i)
		scanf_s("%d", &arr[i]);

	deleteNull(arr, size);

	printf("\n");
	for (int i = 0; i < size; ++i) {
		printf("%d\n", arr[i]);
	}


}