#include <stdio.h>

int optie() {
	char gekozenLetter;
	printf("Select an option ... \n	e: even/odd\n	g: gcd\n	q: quit \n");
	scanf_s(" %c", &gekozenLetter);
	choose(gekozenLetter);
	return 0;
}

int choose(char gekozenLetter) {
	int testgetal;
	int a;
	int b;
	int deler=1;
	if (gekozenLetter == 'e') {
		printf("geef een testgetal: ");
		scanf_s(" %d", &testgetal);
		if (testgetal % 2 == 0) {
			printf("even");
		}
		else {
			printf("oneven");
		}
		return 0;
	}
	else if (gekozenLetter == 'g') {
		printf("Geef het eerste getal: ");
		scanf_s(" %d", &a);
		printf("Geef het tweede getal: ");
		scanf_s(" %d", &b);
		if (a < b) {
			for (int i = 0; i > a; i++) {
				if (a % i == 0 && b % i == 0) {
					deler = i;
				}
			}
		}
		if (a > b) {
			for (int i = 0; i > b; i++) {
				if (a % i == 0 && b % i == 0) {
					deler = i;
				}
			}
		}
		printf("%d is de grootste gemene deler", deler);
		return 0;
	}
	else if (gekozenLetter == 'q') {
		printf("afsluiten...");
		return 0;
	}
	else {
		optie();
	}
}