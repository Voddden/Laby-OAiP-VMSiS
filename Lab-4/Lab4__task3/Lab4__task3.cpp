#include <stdio.h>
#include <locale.h>


void main() {
	setlocale(LC_ALL, "ru");
	//printf("\x1B[31mКрасный\033[0m");
	printf("\x1B[31mred\033[0m");
}