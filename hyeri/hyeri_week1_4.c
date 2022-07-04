//hyeri_week1_4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//소수 판별 및 소수 합 구하는 함수 미리 선언
void number(int k , int p);

int main(void)
{

	//변수 선언
	int m, n;
	
	scanf("%d", &m);
	scanf("%d", &n);

	//위에서 미리 선언한 함수
	number(m, n);


	return 0;
	
}
//함수 정의(소수가 아예 없을 때는 구현 못 함)

void number(int k, int p)
{
	//변수 선언
	int s=0, i,count, sum =0; //s: num배열의 인덱스 , i:for문의 변수, count:소수 판별을 위한 변수, sum: 소수들의 합 
	int num[10000]; //소수로 판별된 정수 넣는 배열

	for (k; k <= p; k++)
	{
		count = 0;//count값 0으로 초기화

		for (i = 2; i < p; i++)
		{
			if (i < k) 
			{
				if (k % i == 0) //나머지값 0이면 소수 아님
				{
					
					count++; //소수 아니면 count값 증가
				}
					

			}
		}
		
		if (count == 0) //count값 증가되지 않으면 소수(즉, 계속 0이면 소수)
		{
			s++; //인덱스 값 증가
			num[s] = k; //num배열에 소수 저장
			sum += k; //소수들의 합
		}
	
			
	}

	printf("%d\n", sum); //소수들의 합 출력
	printf("%d\n", num[1]); //범위 내 제일 작은 소수 출력
}
