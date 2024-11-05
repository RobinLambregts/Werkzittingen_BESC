#include <stdio.h>

int main() {
	int x = 4;
	int y = 9;
	printf("x=%d, y=%d\n", x, y);
	swap(&x, &y);
	printf("x=%d, y=%d", x, y);
	return 0;
}

int swap(int* x, int* y) {
	int tussenstop;
	tussenstop = *x;
	*x = *y;
	*y = tussenstop;
	//return("%d %d", &x, &y);
}