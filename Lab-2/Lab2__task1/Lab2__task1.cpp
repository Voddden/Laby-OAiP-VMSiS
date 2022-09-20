#include <stdio.h>
//#include "..\ValidationLib\Sum.h";
#include "..\ValidationLib\inputNatural.h";

int main() {
	//printf("%d \n", Sum(3, 1));
	int a = inputNatural("---Enter natural number: ");
	printf("Your number: %d", a);
	return 0;
}