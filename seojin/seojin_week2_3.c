/*
    이코테 99페이지 1이 될 때까지
*/

#include <stdio.h>

int main (void)
{
    int n, k, result = 0, target;
    scanf("%d %d", &n, &k);
    while (1){
        target = (n / k) * k;
        result = result + (n - target);
        n = target;
        // n이 k 보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
        if (n < k) break;
        // k로 나누기
        result = result + 1;
        n = n / k;
    }
    result = result + (n - 1);
    printf("%d", result);

}