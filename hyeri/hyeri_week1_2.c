//hyeri_week1_2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	//변수 선언
	char c[100]; 
	int i ,result = 0;

	scanf("%s", c); //문자열 입력
	
	if ((strlen(c) % 2 )!= 0) //문자열의 길이가 홀수인 경우
	{
		for (i = 0; i < strlen(c) / 2; i++) //정가운데 문자를 제외하고 같음을 비교
		{

			if (c[i] == c[strlen(c) - 1 - i])
				result += 0; //팰린드롬인 경우
			else
				result += 1; //팰린드롬이 아닌 경우
		}
	}
	else //문자열의 길이가 짝수인 경우
	{
		for (i = 0; i < strlen(c) / 2; i++) //정가운데 문자 포함해서 같음을 비교
		{
			if (c[i] == c[strlen(c) - 1 - i])
				result += 0; //팰린드롬인 경우
			else
				result += 1; //팰린드롬이 아닌 경우
		}
	}

	//결과 출력

	if (result == 0) //팰린드롬인 경우
		printf("%d", 1);

	else //팰린드롬이 아닌 경우
		printf("%d", 0);
	return 0;
}
