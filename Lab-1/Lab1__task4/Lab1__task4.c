//������������ 1, ������ 4 ���������: ������ �. �.

/*
�� ������ ������ ���������� ��� ��������.
*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	int num;

	printf("---������� ����� ������: ");
	scanf_s("%d", &num);

	if (num == 1)
		printf("������\n");
	else if (num == 2)
		printf("�������\n");
	else if (num == 3)
		printf("����\n");
	else if (num == 4)
		printf("������\n");
	else if (num == 5)
		printf("���\n");
	else if(num == 6)
		printf("����\n");
	else if (num == 7)
		printf("����\n");
	else if (num == 8)
		printf("������\n");
	else if (num == 9)
		printf("��������\n");
	else if (num == 10)
		printf("�������\n");
	else if (num == 11)
		printf("������\n");
	else if (num == 12)
		printf("�������\n");
	else 
		printf("������ � ����� ������� �� ����������\n");
}