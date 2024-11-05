float somwaarde() {
	float uitkomst = 0;
	float x = 0.9;
	for (float n = 1; n < 10; n++) {
		uitkomst += macht(x,n) / faculteit(x);
	}
	printf("%f \n", uitkomst);
	return 0;
}

float macht(float x, float n) {
	float uitkomst;
	uitkomst = pow(x, n);
	return uitkomst;
}

float faculteit(float x) {
	float uitkomst = x;
	for (float i = 1; i < x; i++) {
		uitkomst = uitkomst * (x - i);
	}
	return uitkomst;
}