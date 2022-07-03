//hyeri_week1_3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//피보나치 함수 선언
int pibonaci(int k);

int main(void)
{
	//변수 선언
	int n;

	scanf("%d", &n); //n값 입력

	printf("%d", pibonaci(n)); //피보나치 함수 결과 출력
	return 0;
}

//피보나치 함수 정의
int pibonaci(int k)
{
	//변수 선언
	int result;

	if (k <= 0)
		result = 0;
	else if (k == 1)
		result = 1;
	else
		result = pibonaci(k - 2) + pibonaci(k - 1);
	return result;  //재귀함수 이용
	
}