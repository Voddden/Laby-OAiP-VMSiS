//������������ 1, ������ 1 ���������: ������ �. �.

/*
������ ������ � ������ ��������. 
����� ������� ������� �����������, ������� ������ ����������� � ����� ��������. 
��������� ������� � ��������� �� ���� ������ ����� �������.
*/

#include <stdio.h>
#include <locale.h>
#include "..\ValidationLib\inputRealPositive.h"

void main()
{
	setlocale(LC_ALL, "ru");

	double h = inputRealPositive("\nh = ");
	double r = inputRealPositive("\nr = ");

	double S_side, S_full, V;
	const double PI = 3.14;

	S_side = h * 2 * PI * r;
	S_full = S_side + 2 * PI * r * r;
	V = PI * r * r * h;

	printf("���������: \n S ���. ����������� = %.2lf \n S ����. ����������� = %.2lf \n ����� = %.2lf \n", S_side, S_full, V);
}