#include <stdio.h>

void main3(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] == %s\n", i, argv[i]);
	}
}

/*
deze in normale main ingeven en debugger properties aanpassen naar arg1,arg2 en dan runnen
*/

/*
malloc():
de strings aaneen hangen en deze met 1 malloc alloceren
*/

/*
realloc():
elke keer de volgende string er aan realloccen, dit vergt veel tijd
*/