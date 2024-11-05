#include <stdio.h>

#define N 2

int matrices() {
	int matrix1[N][N] = { {1,2},{3,4} };
	int matrix2[N][N] = { {5,6},{7,8} };
	int matrix3[N][N];
	int somgetal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			int som = 0;
			for (int k = 0; k < N; k++) {
				somgetal = matrix1[i][k] * matrix2[k][j];
				som += somgetal;
			}
			printf("%d	", som);
		}
		printf("\n");
	}
	return 0;
}