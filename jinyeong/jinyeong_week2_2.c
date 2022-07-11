// 이코테with파이썬 p96 실전 문제 : "숫자 카드 게임"
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER 10000


int max_num(int* arr, int count);

int main(void) {
    int N, M, temp, small = MAX_NUMBER;
    scanf("%d %d", &N, &M);
    int *arr = malloc(sizeof(int) * N);


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &temp);
            if (small > temp) small = temp;
        }
        arr[i] = small;
        small = MAX_NUMBER;
    }
    printf("%d", max_num(arr, N));
    free(arr);
    return 0;
}

int max_num(int* arr, int count) {
    int max_number = 0;
    for (int i = 0; i < count; ++i) {
        printf("%d\n", arr[i]);
        if (max_number < arr[i]) max_number = arr[i];
    }
    return max_number;
}