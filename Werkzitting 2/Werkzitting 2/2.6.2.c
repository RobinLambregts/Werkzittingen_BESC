#include <stdio.h>
#include <stdbool.h>

bool haakjes() {
	bool jaNee = checkhaakjes();
	printf("%s", jaNee ? "true" : "false");
}

int checkhaakjes(){
	char string[] = ")()";
	int ongeslotenHaakjes = 0;
	for (int i = 0; i < strlen(string); i++) {
		char letter = string[i];
		if (letter == '(') {
			ongeslotenHaakjes++;
		}
		if (letter == ')') {
			if (ongeslotenHaakjes /* als da groter is dan 0 */ ) {
				ongeslotenHaakjes--;
			}
			else {
				return false;
			}
		}
	}
	return !ongeslotenHaakjes;
}