//������������ 1, ������ 3 ���������: ������ �. �.

/*
���� ����� ����� a, b � c ���� ���� ������� ���������������, 
������� ������ (����������) �����, 
� ��������������� ������ ������� ��������� "���"
*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	float a, b, c;

	printf("---������� a: ");
	scanf_s("%f", &a);
	printf("---������� b: ");
	scanf_s("%f", &b);
	printf("---������� c: ");
	scanf_s("%f", &c);

	// ������ ���������
	if (a == -b || b == -a)
		printf("%.2f \n", c);
	else if (a == -c || c == -a)
		printf("%.2f \n", b);
	else if (c == -b || b == -c)
		printf("%.2f \n", a);
	else
		printf("���\n");
}