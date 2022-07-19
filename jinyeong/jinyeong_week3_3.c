// BOJ 1292 : "쉽게 푸는 문제"
#include <stdio.h>

int main(void) {
    int arr[1000] = {0}, i = 1, idx = 0, A, B, sum = 0;
    while (1) {
        for (int j = 0; j < i; ++j) { // i번 반복해서 i를 배열에 순서대로 삽입
            arr[idx] = i;
            idx++;
            if (idx == 1000) break; // 1000번째 요소가 채워지면 for문, while문 탈출
        }
        if (idx == 1000) break; // 1000번째 요소가 채워지면 for문, while문 탈출
        i++;
    }

    scanf("%d %d", &A, &B);
    for (int j = A - 1; j < B; ++j) {
        sum += arr[j]; // sum에 A ~ B 구간합 저장
    }

    printf("%d", sum);
    return 0;
}