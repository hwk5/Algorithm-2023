#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double logB(double x, double base) {
	return log(x) / log(base);
}

int main() {
	printf("log2(1024) = %0.lf", logB(1024.0, 2.0));

	return 0;
}
