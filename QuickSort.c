#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �� ���� �˰����� ������ �Լ�
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        // �Ǻ��� �迭�� ���� ���� ���ҷ� ����
        int pivot = arr[left];
        int i = left, j = right;
        int tmp;

        // i�� j�� ���� ������ �ݺ�
        while (i < j) {
            // �����ʺ��� �Ǻ����� ���� ���� ã�´�.
            while (arr[j] > pivot) j--;
            // ���ʺ��� �Ǻ����� ū ���� ã�´�.
            while (i < j && arr[i] <= pivot) i++;
            // i�� j�� ������ ���� ���, arr[i]�� arr[j]�� ��ȯ�Ѵ�.
            if (i < j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        // i�� j�� ���� ��ġ�� �Ǻ��� ����, �� ��ġ�� ��ȯ�Ѵ�.
        arr[left] = arr[j];
        arr[j] = pivot;

        // �Ǻ��� �߽����� ���ʰ� ������ �κ� ������ ��������� �ذ��Ѵ�.
        quickSort(arr, left, j - 1); // �Ǻ����� ���� �׷�
        quickSort(arr, j + 1, right); // �Ǻ����� ū �׷�
    }
}

int main() {
    int arr[100];
    int i, n = 0;

    // ���Ͽ��� �����͸� �о���δ�.
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("������ �б� ����.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(fp);

    // �� ���� �˰����� ȣ���Ͽ� �����͸� �����Ѵ�.
    quickSort(arr, 0, n - 1);

    // ����� ���Ͽ� ����.
    fp = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("��� ���� ����.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);

    return 0;
}
