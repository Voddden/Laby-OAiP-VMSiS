#include <stdio.h>
#include "_clearInput.h";

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