#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, tmp;

    for (i = 0; i < n - 1; i++) {
        // 배열의 i번째 원소부터 n-1번째 원소 중에서 가장 작은 값을 찾는다.
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // 배열의 i번째 원소와 가장 작은 값을 가진 원소를 교환한다.
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

int main() {
    int arr[100];
    int i, n = 0;

    // 파일에서 데이터를 읽어들인다.
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("데이터 읽기 실패.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(fp);

    // 선택 정렬 알고리즘을 호출하여 데이터를 정렬한다.
    selectionSort(arr, n);

    // 결과를 파일에 쓴다.
    fp = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("결과 쓰기 실패.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);

    return 0;
}
