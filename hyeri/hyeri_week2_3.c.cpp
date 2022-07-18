//hyeri_week2_3.c
//1이 될 때까지(아코테 with 파이썬 p.99)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, k, num = 0;
	//n,k 값 입력받기(n>k)
	scanf("%d %d", &n, &k);

	//n이 k로 나누어지지 않을 경우 1 뺴고 num 횟수 증가
	while (n % k != 0)
	{
		n -= 1;
		num++;
	}
	//n이 k로 나누어질 경우 k로 나누고 num 횟수 증가
	while (n > 1)
	{

		n= n / k;
		num++;
	}

	//결과값 출력
	printf("%d", num);
	return 0;
}