//수 정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n = 0;
	int num[1000];		//필요한 변수들 선언
	int least, temp, j;

	scanf("%d", &n);	//입력할 수의 개수

	for (int i = 0; i < n; i++) {	//입력한 수들을 num[1000]에 저장
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n - 1; i++)		//차례대로 오름차순 정렬
	{
		least = i;
		for (j = i + 1; j < n; j++)
			if (num[j] < num[least])
				least = j;
		temp = num[i];
		num[i] = num[least];
		num[least] = temp;

	}

	for (int i = 0; i < n; i++)		//오름차순 정렬을 한 수들을 출력
		printf(" %d", num[i]);
	
	return 0;
	
}