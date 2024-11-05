#include <stdio.h>

int interpoleer() {
	int x1 = 1;
	int y1 = 10;
	int x2 = 2;
	int y2 = 20;
	float floatingPoint = 0.5;
	float xUitkomst;
	float yUitkomst;
	xUitkomst = (x2 - x1) * floatingPoint + x1;
	yUitkomst = (y2 - y1) * floatingPoint + y1;
	printf("x-waarde= % f \ny-waarde= % f \nEbbe is een toffe jongen\n", xUitkomst, yUitkomst);
	return 0;
}