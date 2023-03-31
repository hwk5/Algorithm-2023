#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a[10], MAX=0, i;

	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]); 
		if (a[i] > MAX) {
		  MAX = a[i];
        }
	}
	printf("최대숫자: %d", MAX);
	return 0;
}
