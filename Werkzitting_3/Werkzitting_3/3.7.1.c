#include <stdio.h>

#define N 10

void kleinGroot(int array[]) {
	int nummers[N] = { 0 };
	//nummers = &array;

	printf("%d",*nummers);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
		}
	}
}

void tweeArrays() {
	int nums[N] = { 0,7,6,3,4,5,2,1,8,9 };
	int* ptrs[N];

	for (int i = 0; i < N; i++) {
		ptrs[i] = &nums[i];
	}
	kleinGroot(ptrs);
}