#include <stdio.h>

#define N 4

void vectoren() {
	float vector1[N] = { 1,8,6,3 };
	float vector2[N] = { 9,6,1,8 };
	float uitkomst[N] = {0};
	
	for (int i = 0; i < N; i++) {
		*(uitkomst + i) = *(vector1 + i) * *(vector2 + i);
	}
	printf("%f",uitkomst);
}