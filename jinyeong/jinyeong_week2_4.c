// BOJ 1541 : "잃어버린 괄호"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char expression[51], temp[6] = {0}, operator = '+';
    int sum = 0, j = 0;
    scanf("%s", expression);// 수식 입력 받기
    for (int i = 0; i < strlen(expression); ++i) { //문자열 길이만큼 반복
        if (expression[i] == '+') { // 수가 아닌 연산자 '+'를 만났을 때
            if (operator == '+') sum += atoi(temp); // 이전 연산자 중 '-'가 없으면
            else if (operator == '-') sum -= atoi(temp); // 이전 연산자 중 '-'가 있으면
            memset(temp, 0, 6 * sizeof(char)); // 수를 저장할 temp 배열 '\0'으로 재할당
            j = 0;
        } else if (expression[i] == '-') { // 수가 아닌 연산자 '-'를 만났을 때
            if (operator == '+') sum += atoi(temp); // 이전 연산자 중 '-'가 없으면
            else if (operator == '-') sum -= atoi(temp); // 이전 연산자 중 '-'가 있으면
            operator = '-'; // '-' 가 존재하게 되므로 이후의 연산자는 무의미
            memset(temp, 0, 6 * sizeof(char));
            j = 0;
        } else { // 수인 경우 temp배열에 저장
            temp[j] = expression[i];
            j++;
        }
    }
    // 마지막 수 계산
    if (operator == '+') sum += atoi(temp); // 이전 연산자 중 '-'가 없으면
    else if (operator == '-') sum -= atoi(temp); // 이전 연산자 중 '-'가 있으면
    printf("%d", sum);
    return 0;
}

