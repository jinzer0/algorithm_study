#include <stdio.h>
#include <math.h>

int is_prime(int); // 소수인지 판별하는 함수. 소수이면 1을 반환하고 소수가 아니면 0 반환

int main(void) {
    int M, N, min = -1, sum = 0;

    scanf("%d\n%d", &M, &N);
    for (int i = M; i <= N; ++i) {
        if (is_prime(i)) { // 소수이면
            if (min == -1) { // 최솟값이 없으면
                min = i; // 최솟값 저장
            }
            sum += i; // 소수 합 저장
        }
    }
    if (min == -1) printf("-1"); // 소수가 존재하지 않으면 -1 출력, 아니면 소수의 합과 최솟값 출력
    else {
        printf("%d\n%d", sum, min);
    }
}


int is_prime(int M) {
    if (M == 1) return 0;
    if (M == 2) return 1;
    for (int i = 2; i < (int) sqrt(M) + 1; ++i) {
        if (M % i == 0) return 0;
    }
    return 1;
}