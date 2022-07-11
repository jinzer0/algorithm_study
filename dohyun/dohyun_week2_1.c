//ū ���� ��Ģ
// 큰 수의 법칙(p92)
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>

int main(void)
{
	int N, M, K;
	int temp;
	int list[1000];
	int idx = 0;
	int count = 0;
	int result = 0;

	scanf_s("%d %d %d", &N, &M, &K);

	do {
		scanf_s("%d", list + (idx++));
	} while (getc(stdin) == ' ');

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1) - i; j++) {
			if (list[j] < list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}

	count = M / (K + 1) * K + M % (K + 1);

	result=count*list[0] + list[1]*(M-count);

	printf("%d", result);

	return 0;	
}