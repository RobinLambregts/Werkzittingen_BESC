#include <stdio.h>

int main() {
	optie();
	//somwaarde();
	//fizzBuzz();
	//getVaaksteLetter(iet me scanf)
	//interpoleer();
	return 0;
}

int getVaaksteLetter(char characters[]){
	char character1;
	char character2;
	int counter = 0;
	int hoogstecounter = 0;
	int meestvoorkomend;
	for (int i=0; i<sizeof(characters); i++){
		character1 = getchar(characters, i);
		character2 = getchar(characters, i + 1);
		if (character1 = character2) {
			counter++;
		}
		else
			if (counter > hoogstecounter) {
				meestvoorkomend = character1;
				hoogstecounter = counter;
				counter = 0;
			}
	}
	printf(hoogstecounter);
	return 0;
}