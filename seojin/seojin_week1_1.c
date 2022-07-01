/* 
    문제 2750번 [수 정렬하기]
    1. 첫째 줄에 수의 개수 N입력 (1이상 1000이하)
    2. 둘째 줄부터 N개의 줄에 수 입력.(절댓값이 1000이하, 중복되지 않음)
    3. 오름차순 정렬 (순차 정렬)
    4. 정렬 결과 출력
*/

#include <stdio.h>

int main (void)
{
    int list[1000];
    int n, i, j, temp;

    //1. 첫째 줄에 수의 개수 N입력 (1이상 1000이하)
    scanf("%d", &n);
    
    //2. 둘째 줄부터 N개의 줄에 수 입력.(절댓값이 1000이하, 중복되지 않음)
    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);
    
    //3. 오름차순 정렬 (순차 정렬)
    for ( i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){  //list[i+1]와 list[n-1] 사이의 값이 list[i] 보다 클 경우 값을 교환한다.  
            if (list[i] > list[j]){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    //4. 정렬 결과 출력
    for (i = 0; i < n; i++)
        printf("%d\n", list[i]);

    return 0;
}
