#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "..\ValidationLib\inputSN.h"
#include "..\ValidationLib\inputReal.h"
#include "..\ValidationLib\inputNatural.h"

/*
��� ������ � ������� n, �� ���������� ������� ���������. 
���������� �������� ������ �, � ������� ������� ���� ������������� ��������, 
� ����� �������������. �������������� ������� �� ������������.
*/

void main() {
	setlocale(LC_ALL, "ru");
	double a = inputReal("����� ������������ �����: ");
	

	int n = inputSN("����� ����������� �����: ");
	printf("real = %lf", a);
	printf("\nSN = %d", n);

}