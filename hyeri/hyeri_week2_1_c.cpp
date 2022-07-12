//hyeri_week2_1.c
//큰 수의 법칙(아코테 with 파이썬 p.92)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 선언
int first_big_num(int arr[],int k);
int second_big_num(int arr[],int k);
int main(void)
{
	int n, m, k,i ,p=0,result =0;
	int num[100];

	//N,M,K 입력받기
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++)
	{
		//n개의 수 입력받기
		scanf("%d", &num[i]);
	}
	
	//가장 큰 수를 k번, 두 번째로 큰 수를 1번 더한 후 결과값 도출하는 부분

	while (1)
	{
		for (p = 0; p < k; p++)
		{
			if (m == 0)
				break;
			result += first_big_num(num, n);
			m -= 1;
		}
		if (m == 0)
			break;
		result += second_big_num(num, n);
		m -= 1;
	}



	//결과값 출력
	printf("%d", result);
	return 0;
}

//함수 정의:배열에서 가장 큰 수를 출력하는 함수
int first_big_num(int arr[], int k)
{
	int i,j , temp;

	//배열arr[]을 오름차순으로 정렬
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < (k - 1) - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//가장 큰 수 출력
	return arr[k-1];
}

//함수 정의:배열에서 가장 큰 수를 출력하는 함수
int second_big_num(int arr[], int k)
{
	int i, j, temp;

	//배열arr[]을 오름차순으로 정렬
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < (k - 1) - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//두 번째로 큰 수 출력
	return arr[k-2];
}