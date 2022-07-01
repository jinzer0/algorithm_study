/*
    다이나믹 프로그래밍, 자료형
    문제 2748번 [피보나치 수 2]
    1. n값 입력(90보다 작거나 같은 자연수)
    2. n번째 피보나치 수 출력
*/
#include <stdio.h>
#include <stdlib.h>
#define max 90

int main (void)
{
    long long list[max] = {0,};
    int n, i;
    list[0] = 1;
    list[1] = 1;
    scanf("%d", &n);
    if (n > 90) return 0;
    for(i = 2; i < n; i++)
    {
        list[i] = list[i - 1] + list[i-2];
    }
    printf("%lld", list[n-1]);
    return 0; 
}