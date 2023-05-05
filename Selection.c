#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int p = partition(arr, low, high);
        if (p - low == k - 1) {
            return arr[p];
        }
        if (p - low > k - 1) {
            return kthSmallest(arr, low, p - 1, k);
        }
        return kthSmallest(arr, p + 1, high, k - p + low - 1);
    }
    return -1;
}

int main() {
    FILE* input = fopen("data.txt", "r");
    if (input == NULL) {
        printf("입력파일 실행 오류\n");
        return 1;
    }

    FILE* output = fopen("result.txt", "w");
    if (output == NULL) {
        printf("출력파일 실행 오류\n");
        fclose(input);
        return 1;
    }

    int arr[1000];
    int n, k;

    fscanf(input, "%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &arr[i]);
    }

    int result = kthSmallest(arr, 0, n - 1, k);

    if (result == -1) {
        printf("Invalid input\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fprintf(output, "%d\n", result);

    fclose(input);
    fclose(output);

    return 0;
}
