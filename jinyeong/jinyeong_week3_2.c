// 이코테with파이썬 p118 실전 문제 : "게임 개발"
#include <stdio.h>
#include <stdlib.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

void turn(int *); // 왼쪽으로 방향을 도는 함수

int main(void) {
    int N, M, col, row, head, count = 0, limit = 0, x = 0, y = 0;
    scanf("%d %d", &N, &M); // N열, M행 입력
    scanf("%d %d %d", &col, &row, &head); // 현재 위치, 방향 입력
    // N * M 2차원 배열 동적 할당
    int **map = malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i) {
        map[i] = malloc(M * sizeof(int));
    }
    map[row][col] = 2;

    for (int i = 0; i < N; ++i) { // 맵의 각 칸 입력 (1 : 바다, 0 : 육지)
        for (int j = 0; j < M; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    while (1) { // 육지로 이동하는 경우
        turn(&head); // 왼쪽 반시계 방향으로 돌기
        switch (head) { // 방향에 따라 이동할 좌표 구하기
            case NORTH:
                y = 1;
                break;
            case SOUTH:
                y = -1;
                break;
            case EAST:
                x = 1;
                break;
            case WEST:
                x = -1;
                break;
        }
        if (map[row + y][col + x] == 0) { // 이동할 좌표가 0, 육지인 경우
            map[row + y][col + x] = 2; // 이미 이동했다는 표시로 2 저장
            count++; // 이동 횟수 증가
            limit = 0;
            row += y; // 현재 위치(열) 업데이트
            col += x; // 현재 위치(행) 업데이트
        } else if (map[row + y][col + x] == 1 || map[row + y][col + x] == 2) { // 이동할 좌표가 1 혹은 2, 바다 혹은 이미 가본 곳인 경우
            limit++; // 반복 횟수 증가. limit가 4 이상 = 네개 방향을 모두 둘러본 것
        }
        if (limit > 3) break; // 사면이 바다 혹은 이미 가본 곳인 경우 탈출
        // 초기화
        x = 0;
        y = 0;
    }

    while (1) { // 모든 육지를 이동하고 나서 다시 뒤로 가는 경우
        switch (head) {  // 현재 방향의 반대 방향으로 이동해야함
            case NORTH:
                y = -1;
                break;
            case SOUTH:
                y = 1;
                break;
            case EAST:
                x = -1;
                break;
            case WEST:
                x = 1;
                break;
        }

        if (map[row + y][col + x] == 2) { // 이동할 위치가 이미 가본 곳인 경우
            map[row + y][col + x] = 3; // 이미 가본 곳을 다시 가는 것이므로 3 저장
            count++; // 이동 횟수 증가
            // 현재 위치 업데이트
            row += y;
            col += x;
        } else break;
        x = 0;
        y = 0;
    }

    printf("count : %d", count); // 최종 이동 횟수 출력

    // 동적 할당 메모리 해제
    for (int i = 0; i < N; ++i) {
        free(map[i]);
    }
    free(map);
    return 0;
}

void turn(int *head) {
    switch (*head) {
        case NORTH:
            *head = WEST;
            break;
        case SOUTH:
            *head = EAST;
            break;
        case EAST:
            *head = NORTH;
            break;
        case WEST:
            *head = SOUTH;
            break;
    }
}