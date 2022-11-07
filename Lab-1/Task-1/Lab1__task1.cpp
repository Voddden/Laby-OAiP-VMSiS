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

	double h = inputRealPositive("h = ");
	double r = inputRealPositive("r = ");

	double S_side, S_full, V;
	const double PI = 3.14;

	S_side = h * 2 * PI * r;
	S_full = S_side + 2 * PI * r * r;
	V = PI * r * r * h;

	printf("S_side = %.2lf\nS_full = %.2lf\nV = %.2lf\n", S_side, S_full, V);
}