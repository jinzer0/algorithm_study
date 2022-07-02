/*
    문제 2581번 [소수]
    1. 자연수 M ,N 입력 (M <= N)
    2. M이상 N 이하 자연수 중 소수인 것을 고른다.
    3. 이들 소수의 합과 최솟값을 찾는다.
    4. 소수가 없을 경우 -1 출력
    5. 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값 출력
*/
#include <stdio.h>
int isPrime(int k);//소수이면 0, 아니면 -1 반환

int main (void)
{
    int m, n, min, sum = 0, i; //m은 n보다 작거나 같다. 
    
    //1
    scanf("%d", &m);
    scanf("%d", &n);

    //2, 3
    for (i = m; i <= n; i++){
        if(isPrime(i) == 0){ // 소수인 경우
            if (sum == 0){ //최솟값 저장
               min = i;
            }
            sum = sum + i;
        }
    }

    //4. 소수가 없는 경우 > -1 출력
    if (sum == 0) {
        printf("-1");
        return 0;
    }

    //5
    printf("%d\n%d",sum,min);
    return 0;
}

int isPrime(int k) //소수이면 0, 아니면 -1 반환
{
    if (k == 1) return -1;
    if (k == 2) return 0;
    for (int i = 2 ; i < k; i ++){
        if ( k % i == 0) return -1;
    }
    return 0;
}
