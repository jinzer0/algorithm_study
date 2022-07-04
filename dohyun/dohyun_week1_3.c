//피보나치

#include <stdio.h>

int main(void)
{
	long long n, result, a, b;

	a = 0;
	b = 1;
	result = 0;

	scanf("%lld", &n);

	if (n == 0){				//n=0 일 경우 값은 0
		printf("0");
	}
	else if (n == 1) {			//n=1 일 경우 값은 1
		printf("1");
	}
	else {

		for (int i = 1; i < n; i++)		//n=2 이상부터는 for루프를 사용하여 계산
		{
			result = a + b;
			a = b;
			b = result;
		}
		printf("%lld", result);			//n번째 값 출력
	}
	
	return 0;

}	