// 이코테with파이썬 p92 실전 문제 : "큰 수의 법칙"
#include <stdio.h>

void sort(int *arr, int count);

int main(void) {
    int N, M, K, arr[1000], sum = 0, count = 0;
    scanf("%d %d %d", &N, &M, &K); // N, M, K 입력받음
    for (int i = 0; i < N; ++i) { // arr 배열에 N개 만큼의 수 입력받음
        scanf("%d", arr + i);

    }
    sort(arr, N); // arr 배열내 원소 내림차순 정렬 (예/ 6, 3, 2...)
    for (int i = 0; i < M; ++i) { // N번 수를 sum에 합함
        count++; // 특정 인덱스의 원소를 연속해서 몇번 합하는지 저장하는 변수. 이 변수값이 K를 초과하는 경우 다른 인덱스의 원소를 더함
        if (count <= K) sum += arr[0]; // 장 큰 수를 더함
        else { // 두번째로 큰 수를 더함
            sum += arr[1];
            count = 0;
        }
    }
    printf("%d", sum);
    return 0;
}

void sort(int *arr, int count) { // 배열을 내림차순으로 선택정렬
    int max_idx, temp;
    for (int i = 0; i < count - 1; ++i) {
        max_idx = i;
        for (int j = i + 1; j < count; ++j) {
            if (arr[max_idx] < arr[j]) max_idx = j;
        }
        temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}