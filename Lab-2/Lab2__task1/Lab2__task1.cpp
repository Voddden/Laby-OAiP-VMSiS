#include <stdio.h>
#include <locale.h>

/*
������� ��������� ������ ����  �  �����  1+1/2+1/3+1/4+...+1/n, 
����� ��� ����� ��������� ������ 5 ?
*/

void main() 
{
	setlocale(LC_ALL, "ru");
	float sum = 0;
	int i = 1;
	for (; sum <= 5; ++i) {
		sum += 1.0 / (float)i;
	}

	printf("����� %d ���������", i);
}