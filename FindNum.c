#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Array 8 

int main()
{
	int num[Array] = { 55,43,98,3,73,87,59,18 };
	int K, i;

	printf("숫자찾기 입력:");
	scanf_s("%d", &K);

	for (i = 0; i < Array; i++)
	{
		if (num[i] == K)
		{
			printf("%d 번째 인덱스에 있네요.\n", i);
			break;
		}
	}
	return 0;
}
