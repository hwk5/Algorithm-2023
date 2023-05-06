#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE]; //입력값 배열
int tmp[MAX_SIZE]; //임시 배열

void merge(int start, int mid, int end) { //두 부분 배열을 합병하는 함수
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) { // 두 부분 배열에 대해
        if (arr[i] <= arr[j]) { // 첫 번째 부분 배열의 값이 더 작으면
            tmp[k++] = arr[i++]; // 임시 배열에 넣고 인덱스 증가
        }
        else { // 두 번째 부분 배열의 값이 더 작으면
            tmp[k++] = arr[j++]; // 임시 배열에 넣고 인덱스 증가
        }
    }

    while (i <= mid) { // 첫 번째 부분 배열에 대해
        tmp[k++] = arr[i++]; // 남은 값을 임시 배열에 넣고 인덱스 증가
    }

    while (j <= end) { // 두 번째 부분 배열에 대해
        tmp[k++] = arr[j++]; // 남은 값을 임시 배열에 넣고 인덱스 증가
    }

    for (int l = start; l <= end; l++) { // 임시 배열에 저장된 값을 원래 배열에 복사
        arr[l] = tmp[l];
    }
}

void merge_sort(int start, int end) { //합병 정렬 함수
    if (start >= end) { //배열 크기가 1이하면 정렬 완료
        return; 
    }

    int mid = (start + end) / 2; // 중간 지점 인덱스 계산

    merge_sort(start, mid); // 첫 번째 부분 배열에 대해 재귀 호출
    merge_sort(mid + 1, end); // 두 번째 부분 배열에 대해 재귀 호출
    merge(start, mid, end); // 두 부분 배열을 합병

}

int main() {
    FILE* fp_in = fopen("data.txt", "r"); // 입력 파일 열기
    FILE* fp_out = fopen("result.txt", "w"); // 출력 파일 열기

    int n = 0; // 입력값 개수

    while (fscanf(fp_in, "%d", &arr[n++]) != EOF) { // 파일에서 입력값을 읽어옴
        if (n >= MAX_SIZE) { // 입력값 개수가 최대 개수를 초과할 경우
            fprintf(stderr, "에러: 입력값 초과\n"); // 오류 메시지 출력
            return 1; // 비정상 종료
        }
    }

    n--; // 입력값 개수 조정

    merge_sort(0, n - 1); // 합병 정렬 수행

    for (int i = 0; i < n; i++) { //정렬된 값 출력 파일에 저장
        fprintf(fp_out, "%d\n", arr[i]);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
