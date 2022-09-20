//Лабораторная 1, задача 3 Выполнена: Воднев Д. И.

/*
Если среди чисел a, b и c есть пара взаимно противоположных, 
вывести третье (оставшееся) число, 
в противоположном случае вывести сообщение "нет"
*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	float a, b, c;

	printf("---Введите a: ");
	scanf_s("%f", &a);
	printf("---Введите b: ");
	scanf_s("%f", &b);
	printf("---Введите c: ");
	scanf_s("%f", &c);

	// начало алгоритма
	if (a == -b || b == -a)
		printf("%.2f \n", c);
	else if (a == -c || c == -a)
		printf("%.2f \n", b);
	else if (c == -b || b == -c)
		printf("%.2f \n", a);
	else
		printf("нет\n");
}