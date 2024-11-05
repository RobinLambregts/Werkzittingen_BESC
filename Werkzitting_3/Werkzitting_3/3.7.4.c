#include <stdio.h>

void stringOmdraaien() {
	char woord[] = "mathias";
	int len = strlen(woord);

	for (int i = 0, j = len - 1; i <= j; i++, j--) {
		char c = *(woord+i);
		*(woord+i) = *(woord + j);
		*(woord + j) = c;
	}
	printf("%s", woord);
}