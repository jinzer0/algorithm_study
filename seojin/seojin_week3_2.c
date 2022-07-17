#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int row, col, i, j; //맵 생성을 위한 변수들
	int x, y, direction; //현재 캐릭터에 대한 정보를 위한 변수들
	int left_x, left_y; //캐릭터의 왼쪽 방향의 정보를 위한 변수들
	int count = 0; // 동서남북 검사 횟수
	int result = 0; //방문한 칸의 수 세기

	scanf("%d %d", &row, &col); //가로 세로 크기 입력

	int** map; //이차원 동적할당 생성
	map = malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++)
		map[i] = malloc(sizeof(int) * col);

	scanf("%d %d %d", &x, &y, &direction);// 캐릭터 정보 입력
	for (i = 0; i < row; i++) //맵 정보 입력
	{
		for (j = 0; j < col; j++)
			scanf(" %d", &map[i][j]);
	}
	
	map[x][y] = -1; //가본땅은 -1, 바다는 1, 가보지 않은 땅은 0
	result = result + 1;

	while (1)//시뮬레이션 시작
	{
		switch (direction) { //left_x, left_y에 캐릭터의 왼쪽 좌표 저장
		case 0: // 북
			left_x = x - 1; left_y = y;
			break;
		case 1: //동
			left_x = x; left_y = y + 1;
			break;
		case 2: //남
			left_x = x + 1; left_y = y;
			break;
		case 3://서
			left_x = x; left_y = y - 1;
			break;
		}
		if (map[left_x][left_y] == 0) //바다가 아니거나 아직 가보지 않은 칸이라면
		{
			if (direction == 0) direction = 3; // 방향 전환
			else direction = direction - 1;
			x = left_x; y = left_y; //이동
			map[left_x][left_y] = -1; //가본 땅으로 변경
			count = 0;
			result = result + 1;
		}
		else if (map[left_x][left_y] != 0) //바다이거나 가본 땅이라면
		{
			if (count == 4) //동서남북 모두 검사했다면
			{
				switch (direction) { //한 칸 뒤로가기
				case 0: // 북
					x = x + 1; y = y;
					break;
				case 1: //동
					x = x; y = y - 1;
					break;
				case 2: //남
					x = x - 1; y = y;
					break;
				case 3://서
					x = x; y = y + 1;
					break;
				}
				if (map[x][y] == 1) break; //바다라면 종료 (뒤가 바다로 막혀있는 경우)
				else if (map[x][y] == -1 ){ // 바다가 아니라 가본 땅이라면
					result = result + 1;
					count = 0;
				}
			}
			else
			{
				count++;
				if (direction == 0) direction = 3; // 방향 전환
				else direction = direction - 1;
			}
		}
	}
	printf("%d", result); //결과 출력
	for (i = 0; i < row; i++) //동적 할당 해재
		free(map[i]);
	free(map);
	return 0;
}