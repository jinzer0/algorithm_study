/*
    아코테 92페이지 큰 수의 법칙
    다양한 수로 이루어진 배열이 있을 때 주어진 수들을 M번 더하여 가장 큰 수를 만드는 법칙
    단, 배열의 특정한 인덱스(번호)에 해당하는 수가 연속해서 K번을 초과하여 더해질 수 없음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    // N, M, K 공백으로 구분하여 입력받기
    int n, m, k, buf, i, j, temp;
    int count, result=0;
    int data[10000]; // N개의 수를 저장할 공간
    scanf("%d %d %d", &n, &m, &k);

    //N개의 수 공백으로 구분하여 입력받기
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &buf); // ' '를 포함하여 공백 처리
        data[i] = buf;
    }

    //정렬
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {  //list[i+1]와 list[n-1] 사이의 값이 list[i] 보다 클 경우 값을 교환한다.  
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    //가장 큰 수가 더해지는 횟수 계산
    count = (int)((m / (k + 1)) * k);
    count = count + m % (k + 1);

    result = result + count *  data[n - 1]; // 가장 큰 수
    result = result + (m - count) * data[n - 2];//두 번째로 큰 수
    printf("%d", result);
    return 0;
}
