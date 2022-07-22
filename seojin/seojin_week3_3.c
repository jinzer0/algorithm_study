#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B, list, count = 1, result = 0, i; //A, B, list는 수열의 인덱스, count는 수열의 항 의미
	scanf("%d %d", &A, &B);
 
	for (list = 1; list <= B; count++){ // 수열의 첫번째 항부터 B번째 항까지 반복문 진행
		for (i = 0; i < count; i++){ // count를 count번 더한다
			if ((list >= A) && (list<=B)) result = result + count; //설정 범위 안의 인덱스일 경우 result에 값 저장
			list++; //설정범위 안, 밖 모든 경우에 항의 인덱스는 증가
		}
	}
	printf("%d", result);
	return 0;
}
//
