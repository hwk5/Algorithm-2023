#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int arr[MAX_SIZE]; //�Է°� �迭
int tmp[MAX_SIZE]; //�ӽ� �迭

void merge(int start, int mid, int end) { //�� �κ� �迭�� �պ��ϴ� �Լ�
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) { // �� �κ� �迭�� ����
        if (arr[i] <= arr[j]) { // ù ��° �κ� �迭�� ���� �� ������
            tmp[k++] = arr[i++]; // �ӽ� �迭�� �ְ� �ε��� ����
        }
        else { // �� ��° �κ� �迭�� ���� �� ������
            tmp[k++] = arr[j++]; // �ӽ� �迭�� �ְ� �ε��� ����
        }
    }

    while (i <= mid) { // ù ��° �κ� �迭�� ����
        tmp[k++] = arr[i++]; // ���� ���� �ӽ� �迭�� �ְ� �ε��� ����
    }

    while (j <= end) { // �� ��° �κ� �迭�� ����
        tmp[k++] = arr[j++]; // ���� ���� �ӽ� �迭�� �ְ� �ε��� ����
    }

    for (int l = start; l <= end; l++) { // �ӽ� �迭�� ����� ���� ���� �迭�� ����
        arr[l] = tmp[l];
    }
}

void merge_sort(int start, int end) { //�պ� ���� �Լ�
    if (start >= end) { //�迭 ũ�Ⱑ 1���ϸ� ���� �Ϸ�
        return; 
    }

    int mid = (start + end) / 2; // �߰� ���� �ε��� ���

    merge_sort(start, mid); // ù ��° �κ� �迭�� ���� ��� ȣ��
    merge_sort(mid + 1, end); // �� ��° �κ� �迭�� ���� ��� ȣ��
    merge(start, mid, end); // �� �κ� �迭�� �պ�

}

int main() {
    FILE* fp_in = fopen("data.txt", "r"); // �Է� ���� ����
    FILE* fp_out = fopen("result.txt", "w"); // ��� ���� ����

    int n = 0; // �Է°� ����

    while (fscanf(fp_in, "%d", &arr[n++]) != EOF) { // ���Ͽ��� �Է°��� �о��
        if (n >= MAX_SIZE) { // �Է°� ������ �ִ� ������ �ʰ��� ���
            fprintf(stderr, "Error: input size is too large!\n"); // ���� �޽��� ���
            return 1; // ������ ����
        }
    }

    n--; // �Է°� ���� ����

    merge_sort(0, n - 1); // �պ� ���� ����

    for (int i = 0; i < n; i++) { //���ĵ� �� ��� ���Ͽ� ����
        fprintf(fp_out, "%d\n", arr[i]);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
