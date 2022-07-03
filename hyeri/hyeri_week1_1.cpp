//hyeri_week1_1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	// 변수 선언
	int n, i, k,m;
	int num[100];

	//입력 부분

	scanf_s(" %d", &n); //받을 정수 개수 입력
	for (i = 0; i < n; i++) 
	{
		scanf_s(" %d", &num[i]); //정수 개수만큼 정수 입력
	}

	//오름차순으로 정렬

	for (i = 0; i < n; i++) //작은 수를 앞으로 끌어오는 방식의 이중 for문
	{

		for (k = i+1 ; k < n; k++)
		{
			if (num[i] < num[k])  //두 수를 교환하는 부분
			{
				m = num[i];
				num[i] = num[k];
				num[k] = m;
			}
			
		
		}
	}

	//재정렬된 ㅐ열 출력

	for (i = n-1; i >= 0; i--)
		printf("%d\n", num[i]);

	return 0;
}