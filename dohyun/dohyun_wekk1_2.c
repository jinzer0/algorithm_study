//팰린드롬

#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include <string.h>

	int main(void)
	{
		int i=0;
		char str[1000];
		int result = 0;

		scanf("%s", str);	


		for (i = 0; i <strlen(str); i++) //result의 값에 따라 팰린드롬인지 판단
		{
			if( (str[i])  ==  str[strlen(str) - i-1])
				result += 0;
			else 
				result += 1;
		}
	
		if (result == 0) {
			printf("1");//팰린드롬이 아니다
			return 1;
		}
		else
		{
			printf("0");//팰린드롬이다
			return 0;
		}

	}

