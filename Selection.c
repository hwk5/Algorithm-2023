#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// 선택 정렬 함수
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    // 배열의 첫 번째 원소부터 마지막 바로 전 원소까지 반복
    for (i = 0; i < n - 1; i++) {
        // 현재 위치부터 마지막 원소까지 중 가장 작은 원소의 인덱스를 찾음
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 현재 위치와 가장 작은 원소의 위치를 교환
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    // 입력 파일과 출력 파일의 파일 포인터 선언
    FILE* input_file, * output_file;

    // 입력 파일을 읽기 모드로 열기
    input_file = fopen("data.txt", "r");
    if (input_file == NULL) {
        printf("입력파일 열기 실패.\n");
        return 1;
    }

    // 출력 파일을 쓰기 모드로 열기
    output_file = fopen("result.txt", "w");
    if (output_file == NULL) {
        printf("출력파일 열기 실패.\n");
        fclose(input_file);
        return 1;
    }

    // 입력 파일에서 데이터 읽기
    int arr[100];
    int n = 0;
    while (fscanf(input_file, "%d", &arr[n]) == 1) {
        n++;
    }

    // 선택 정렬 함수 호출
    selectionSort(arr, n);

    // 정렬된 결과를 출력 파일에 저장
    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }

    // 파일 포인터 닫기
    fclose(input_file);
    fclose(output_file);

    return 0;
}
