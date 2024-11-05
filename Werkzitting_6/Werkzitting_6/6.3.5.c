#include <stdio.h>
#include <stdbool.h>

#define N 5
#define K 2
#define DELTA 0.00001

void array() {
	int array[N][K] = { {1,2},{3,4},{6,7},{1,2},{1,3} };
	int *p = malloc(sizeof(array[K]));
	int p[0] = array[0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < sizeof(p); j++)
		if (compareInt(array[i], p[j])) {
			break;
		}
		else {
			*(p + sizeof(p)) = array[i];
		}
	}
	*(p + sizeof(p)) = "\0";
	printf(p);
}

bool compareInt(int getal1, int getal2) {
	return (getal1 - getal2) < DELTA;
}