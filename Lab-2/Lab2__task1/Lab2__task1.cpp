#include <stdio.h>
#include "..\ValidationLib\inputReal.h";

void main() 
{
	// задача: предоставить интерфейсы для осуществления 
	//валидированного ввода вещественных чисел

	double f = inputReal("\n---Enter the number: ");
	printf("\nYour number: %f", f);

}