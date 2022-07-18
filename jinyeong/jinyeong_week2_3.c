// 이코테with파이썬 p99 실전 문제 : "1이 될 때까지"
#include <stdio.h>

int main(void) {
    int N, K, count = 0;
    scanf("%d %d", &N, &K);
    while (N != 1) { // N이 1이 될 때까지 반복
        if (N % K == 0) N /= K; //나누어 떨어지면 나누기
        else N -= 1; // 나누어 떨어지지 않으면 1 빼기
        count++; // 횟수 +1
    }
    printf("%d", count);
    return  0;
}