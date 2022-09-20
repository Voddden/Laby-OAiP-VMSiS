#include <stdio.h>

const int length = 1000;
bool InputIsInvalid = false;

void invalidInputDueToSeparators(const char* str) {
	int number_of_separators = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '.' || str[i] == ',')
			++number_of_separators;
	}
	if (number_of_separators > 1)
		InputIsInvalid = true;
}

void invalidInputDueToLetters(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
			str[i] != '3' && str[i] != '4' && str[i] != '5' &&
			str[i] != '6' && str[i] != '7' && str[i] != '8' &&
			str[i] != '9' && str[i] != '.' && str[i] != ',')
		{
			InputIsInvalid = true;
		}
	}
}

double inputReal(const char* prompt) {
	char input[length];
	do {
	printf("%s", prompt);
	scanf_s("%s", input, length); // ввод числа в виде строки
	InputIsInvalid = false;
	// проверки:
	invalidInputDueToLetters(input);
	invalidInputDueToSeparators(input);
	} while (InputIsInvalid);

	printf("input is corresct and = %s", input);
	return 228.0;
	
}