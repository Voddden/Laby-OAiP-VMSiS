#include <stdio.h>
#include "../ValidationLib/inputReal.h"
#include "../ValidationLib/inputSN.h"


void main() {

	//double f = inputReal("enter double: ");
	//printf("\nyour double number:  %lf\n", f);
	int a = inputSN("Enter natural number: ");
	printf("your number: %d", a);
}