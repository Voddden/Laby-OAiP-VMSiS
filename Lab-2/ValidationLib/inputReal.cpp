#include <stdio.h>
#include <stdlib.h>

const int length = 1000;

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

double parseFractPartToDouble(const char* str) {
	int g = 0;
	while (str[g] != '.' && str[g] != ',' && str[g] != '\0') ++g; // g == кол-во цифр в целой части
	int whole_digits = g;
	int u = g;
	for (; str[u] != '\0'; ++u); // u == кол-во цифр вообще в числе
	int all_digits = u - 1;
	int fract_digits = all_digits - whole_digits;

	int arr_int_size = fract_digits;
	int* arr_int = (int*)malloc(arr_int_size * sizeof(int));
	for (int i = 0; i < arr_int_size; ++i) {
		arr_int[i] = str[i + whole_digits + 1] - 48;
	}

	double result = 0;
	int razryad = -1;
	for (int i = 0; i < arr_int_size; ++i) {
		result += arr_int[i] * Pow(10, razryad);
		--razryad;
	}
	return result;
}

double parseWholePartToDouble(const char* str) {
	int g = 0;
	while (str[g] != '.' && str[g] != ',' && str[g] != '\0') ++g; // количество цифр d целой части

	int arr_int_size = g;
	int* arr_int = (int*)malloc(arr_int_size * sizeof(int)); // динамический массив
	for (int i = 0; i < arr_int_size; ++i) {
		arr_int[i] = str[i] - 48;
	}
	double result = 0;

	int razryad = arr_int_size - 1;
	for (int i = 0; i < arr_int_size; ++i) {
		result += arr_int[i] * Pow(10, razryad);
		--razryad;
	}

	return result;
}

bool inputIsInvalidDueToMinuses(const char* str) {
	for (int i = 1; i != '\0'; ++i) {
		if (str[i] == '-')
			return true;
	}
	return false;
}

bool inputIsInvalidDueToSpaces(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ' ')
			return true;
	}
	return false;
}

bool inputIsInvalidDueToSeparators(const char* str) {
	int number_of_separators = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		if (str[i] == '.' || str[i] == ',')
			++number_of_separators;
	if (number_of_separators > 1)
		return true;
}

bool inputIsInvalidDueToLetters(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
			str[i] != '3' && str[i] != '4' && str[i] != '5' &&
			str[i] != '6' && str[i] != '7' && str[i] != '8' &&
			str[i] != '9' && str[i] != '.' && str[i] != ',' //&& str[i] != '-'
			)
		{
			return true;
		}
	}
	return false;
}

double inputReal(const char* prompt) {
	char input[length];

	printf("%s", prompt);
	scanf_s("%s", input, length);

	// Вызов проверяющих функций
	while (inputIsInvalidDueToLetters(input) || inputIsInvalidDueToSeparators(input)// || inputIsInvalidDueToMinuses(input) || inputIsInvalidDueToSpaces(input)
		) 
	{
		// некорректные данные. Повторный ввод
		printf("Error. %s", prompt);
		fflush(stdin);
		scanf_s("%s", input, length);
	}

	char input_unsigned[length + 1];
	if (input[0] == '-') {
		for (int i = 0; i < length - 1; ++i) {
			input_unsigned[i] = input[i + 1];
		}
	}
	else {
		for (int i = 0; i < length; ++i) {
			input_unsigned[i] = input[i];
		}
	}

	double res = 0;
	// парсинг целой части
	res += parseWholePartToDouble(input);
	// парсинг дробной части
	res += parseFractPartToDouble(input);
	//установление необходимого знака


	return res;
	
}