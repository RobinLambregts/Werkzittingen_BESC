#include <stdio.h>

int whitespaceRemover() {
	char woord[] = "ik ben Robin               ";
	int indexLaatsteLetter = 0;
	for (int i = 0; i < strlen(woord); i++) {
		if (woord[i] != ' ' && woord[i] != '\n' && woord[i] != '\0') {
			indexLaatsteLetter = i;
		}
	}
	woord[indexLaatsteLetter + 1] = '\0';
	printf("%sa", woord);
	return 0;
}