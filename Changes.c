#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int coin[3] = { 500,100,10 };
    int change, i, count[3];

    printf("거스름돈 입력: ");
    scanf_s("%d", &change);

    for (i = 0; i < 3; i++) {
        count[i] = change / coin[i]; //동전갯수 저장
        change = change % coin[i]; //잔돈 저장
        printf("%d원 : %d개\n", coin[i], count[i]);
    }
}
