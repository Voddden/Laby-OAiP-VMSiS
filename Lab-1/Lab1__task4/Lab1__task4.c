//Лабораторная 1, задача 4 выполнил: Воднев Д. И.

/*
По номеру месяца напечатать его название..
*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	int num;

	printf("---Введите номер месяца: ");
	scanf_s("%d", &num);

	if (num == 1)
		printf("Январь\n");
	else if (num == 2)
		printf("Февраль\n");
	else if (num == 3)
		printf("Март\n");
	else if (num == 4)
		printf("Апрель\n");
	else if (num == 5)
		printf("Май\n");
	else if(num == 6)
		printf("Июнь\n");
	else if (num == 7)
		printf("Июль\n");
	else if (num == 8)
		printf("Август\n");
	else if (num == 9)
		printf("Сентябрь\n");
	else if (num == 10)
		printf("Октябрь\n");
	else if (num == 11)
		printf("Ноябрь\n");
	else if (num == 12)
		printf("Декабрь\n");
	else 
		printf("Месяца с таким номером не существует\n");
}