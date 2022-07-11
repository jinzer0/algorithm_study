// 이코테with파이썬 p96 실전 문제 : "숫자 카드 게임"
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER 10000 // 카드 숫자 중 가장 큰 수


int max_num(int* arr, int count);

int main(void) {
    int N, M, temp, small = MAX_NUMBER;
    scanf("%d %d", &N, &M);
    int *arr = malloc(sizeof(int) * N); // 행 개수만큼 공간이 있는 정수 배열 할당 (각 행의 최솟값 저장을 위한 배열)


    for (int i = 0; i < N; ++i) { // 각 행마다 최솟값을 구해 small에 저장, 그리고 arr배열에 행 순서대로 small값 저장
        for (int j = 0; j < M; ++j) {
            scanf("%d", &temp);
            if (small > temp) small = temp;
        }
        arr[i] = small;
        small = MAX_NUMBER;
    }
    printf("%d", max_num(arr, N)); // 각 행의 최솟값이 저장된 배열에서 가장 큰 수를 찾아 출력
    free(arr);
    return 0;
}

int max_num(int* arr, int count) { // 배열에서 가장 큰 수를 반환하는 함수
    int max_number = 0;
    for (int i = 0; i < count; ++i) {
        printf("%d\n", arr[i]);
        if (max_number < arr[i]) max_number = arr[i];
    }
    return max_number;
}