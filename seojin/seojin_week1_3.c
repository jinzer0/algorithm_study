#include <stdio.h>
#define max 90

int main (void)
{
    long long list[max] = {0,}; //피보나치 수를 저장하는 배열
    int n, i;
    list[0] = 1; //첫번째 피보나치 수
    list[1] = 1; //두번째 피보나치 수

    //1. n값 입력(90보다 작거나 같은 자연수)
    scanf("%d", &n);
    if (n > 90) return 0;

    //2. n번째 피보나치 수 출력
    for(i = 2; i < n; i++)
        list[i] = list[i - 1] + list[i-2];

    printf("%lld", list[n-1]);
    return 0; 
}
