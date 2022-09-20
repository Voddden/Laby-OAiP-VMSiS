#include <stdio.h>

void _clearInput() {
	while (getchar() != '\n');
}

void _input(const char* prompt, const char* pattern, void*
	buffer) {
	printf("%s", prompt);
	int scaned = scanf_s(pattern, buffer);
	while (scaned != 1) {
		printf("Wrong! Try again\n");
		printf("%s", prompt);
		_clearInput();
		scaned = scanf_s(pattern, buffer);
	}
}

// √À¿¬Õ¿ﬂ ‘”Õ ÷»ﬂ
int inputNatural(const char* prompt) {
	int value;
	_input(prompt, "%d", &value);
	while (value <= 0) {
		printf("Must be natural. Try again\n");
		_input(prompt, "%d", &value);
	}
	return value;
}