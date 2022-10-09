//Лабораторная 1, задача 2 Выполнил: Воднев Д.И.

/*
Даны два числа a и b. Определите, равны или не равны эти числа.
*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	float a, b;

	printf("---Введите число a: ");
	scanf_s("%f", &a);
	printf("---Введите число b: ");
	scanf_s("%f", &b);

	if (a == b)
		printf("a и b равны\n");
	else
		printf("a и b неравны\n");
}