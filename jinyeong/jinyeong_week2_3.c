// 이코테with파이썬 p99 실전 문제 : "1이 될 때까지"
#include <stdio.h>

int main(void) {
    int N, K, count = 0;
    scanf("%d %d", &N, &K);
    while (N != 1) {
        if (N % K == 0) N /= K;
        else N -= 1;
        count++;
    }
    printf("%d", count);
    return  0;
}