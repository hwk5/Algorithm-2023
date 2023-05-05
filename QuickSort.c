#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 퀵 정렬 알고리즘을 구현한 함수
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        // 피봇을 배열의 가장 왼쪽 원소로 선택
        int pivot = arr[left];
        int i = left, j = right;
        int tmp;

        // i와 j가 만날 때까지 반복
        while (i < j) {
            // 오른쪽부터 피봇보다 작은 값을 찾는다.
            while (arr[j] > pivot) j--;
            // 왼쪽부터 피봇보다 큰 값을 찾는다.
            while (i < j && arr[i] <= pivot) i++;
            // i와 j가 만나지 않은 경우, arr[i]와 arr[j]를 교환한다.
            if (i < j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        // i와 j가 만난 위치에 피봇을 놓고, 그 위치를 반환한다.
        arr[left] = arr[j];
        arr[j] = pivot;

        // 피봇을 중심으로 왼쪽과 오른쪽 부분 문제를 재귀적으로 해결한다.
        quickSort(arr, left, j - 1); // 피봇보다 작은 그룹
        quickSort(arr, j + 1, right); // 피봇보다 큰 그룹
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

    // 퀵 정렬 알고리즘을 호출하여 데이터를 정렬한다.
    quickSort(arr, 0, n - 1);

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
