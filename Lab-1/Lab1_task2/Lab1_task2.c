//������������ 1, ������ 2 ���������: ������ �. �.

/*
���� ��� ����� a � b. ����������, ����� ��� �� ����� ��� �����.
*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	float a, b;

	printf("---������� ����� �: ");
	scanf_s("%f", &a);
	printf("---������� ����� b: ");
	scanf_s("%f", &b);

	if (a == b)
		printf("a � b �����\n");
	else
		printf("a � b �������\n");
}