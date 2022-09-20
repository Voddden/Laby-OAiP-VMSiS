#include <stdio.h>
#include "_input.h";


int inputNatural(const char* prompt) {
	int value;
	_input(prompt, "%d", &value);
	while (value <= 0) {
		printf("Must be natural. Try again\n");
		_input(prompt, "%d", &value);
	}
	return value;
}