#include <stdio.h>
#include "..\ValidationLib\inputReal.h";

void main() 
{
	// ������: ������������ ���������� ��� ������������� 
	//��������������� ����� ������������ �����

	double f = inputReal("\n---Enter the number: ");
	printf("\nYour number: %f", f);

}