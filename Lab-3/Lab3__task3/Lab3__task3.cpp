#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\ValidationLib\inputSN.h"
#include "..\ValidationLib\inputReal.h"
#include "..\ValidationLib\inputNatural.h"

/*
Дан массив А размера n, не содержащий нулевых элементов. 
Необходимо получить массив А, в которой вначале идут положительные элементы, 
а затем отрицательные. Дополнительные массивы не использовать.
*/

void main() {
	setlocale(LC_ALL, "ru");
	double a = inputReal("Введи вещественное число: ");
	

	int n = inputSN("Введи натуральное число: ");
	printf("real = %lf", a);
	printf("\nSN = %d", n);

}