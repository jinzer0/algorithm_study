//소수

#include <stdio.h>

int prime(int p); //소수인지 판단하는 함수

int main(void)
{

	int m, n;
	int min = 0, mexist = 0, sum = 0;
	scanf("%d %d", &m, &n);				//범위 입력

	for (m; m <= n; m++)
	{
		if (prime(m) == 1)				//prime 함수의 리턴값이 1이면 m 은 소수
		{
			if (mexist == 0)			//최소값이 없으면 min에 최소값 m 저장
			{
				min = m;
				mexist = 1;				//최소값이 생기면 더 이상 최소값을 찾을 필요가 없음
			}
			sum += m;					//소수들의 합
		}
	}
	if (sum == 0)						//범위 내에 소수가 없을 떄
	{
		printf("-1");
		return -1;
	}

	printf("%d\n", min);				
	printf("%d", sum);

	return 0;

}

int prime(int p)
{
	if (p == 1)							//1은 소수가 아님
		return 0;
	
	if (p == 2)							//2는 소수
		return 1;
	
	else {								//3 이상의 수일 경우
		
		for (int i = 2; i < p; i++)
			if (p % i == 0)
				return 0;	
		return 1;

	}
}