// 이코테with파이썬 p115 실전 문제 : "왕실의 나이트"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int sum = 0, col_count, row_count;
    char row, col;
    col = getchar(); // 열
    row = getchar(); // 행
    row = atoi(&row);

    // 1. 수평 두 칸, 수직 한 칸 이동시 경우의 수 구하기
    if (col >= 'c' && col <= 'f') col_count = 2; // 열이 c와 f 사이중 하나라면 수평 두 칸을 좌, 우 둘 다 총 2가지의 경우의 수
    else col_count = 1;
    if (row >= 2 && row <= 7) row_count = 2; // 행이 2와 7 사이중 하나라면 수직 한 칸을 상, 하 둘 다 총 2가지의 경우의 수
    else row_count = 1;

    sum += col_count * row_count; // 경우의 수 더하기

    // 2. 수직 두 칸, 수평 한 칸 이동시 경우의 수 구하기
    if (col >= 'b' && col <= 'g') col_count = 2; // 열이 b와 g 사이중 하나라면 수평 한 칸을 좌, 우 둘 다 총 2가지의 경우의 수
    else col_count = 1;
    if (row >= 3 && row <= 6) row_count = 2; // 행이 3와 6 사이중 하나라면 수직 두 칸을 상, 하 둘 다 총 2가지의 경우의 수
    else row_count = 1;

    sum += col_count * row_count; // 경우의 수 더하기

    printf("%d", sum); // a1 : 2, a2 : 3, a5 : 4, g5 : 6, e5 : 8
    return 0;

}