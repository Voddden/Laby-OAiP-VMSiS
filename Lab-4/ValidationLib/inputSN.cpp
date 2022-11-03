#include <stdio.h>
#include <stdlib.h>
//#include "inputReal.cpp"

double Pow(long num, long deg) {
	double result = 1;

	if (deg < 0) {
		deg = -deg;
		for (long i = 0; i < deg; i++) {
			result *= num;
		}

		return 1 / result;
	}
	else {
		for (long i = 0; i < deg; i++) {
			result *= num;
		}

		return result;
	}
}

bool invalidDueSymbols(char str[]) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!('0' <= str[i] && str[i] <= '9'))
			return true;
	}
	return false;
}

bool invalidDueNull(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] != '0')
			return false;
	}
	return true;
}

int inputSN(const char* prompt) {
	const int length = 100;
	char input[length] = {};
	system("cls");
	rewind(stdin);
	printf("\n%s", prompt);
	gets_s(input, length);

	while (invalidDueSymbols(input) || invalidDueNull(input)) {
		system("cls");
		printf("Error. Try again\n%s", prompt);
		gets_s(input);
	}
	int res = 0;
	int q = 0;
	for (; input[q] != '\0'; ++q);
	int razryad = q - 1;
	for (int i = 0; input[i] != '\0'; ++i) {
		res += (input[i] - 48) * (int)Pow(10, razryad);
		--razryad;
	}

	return res;
}