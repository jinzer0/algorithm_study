/*
    문제 1541번 잃어버린 괄호
    1. 99999 보다 작은 수에 대한 연산 (다섯자리 이하의 수들) (수는 0으로 시작할 수 있다)
    2. 입력되는 식은'0'~'9','+','-'로만 이루어 져 있는 길이 50이하의 문자열
    3. 입력되는 식에 괄호를 적절히 쳐서 식의 값을 최소로 만드는 프로그램 작성
    
    [과정]
    1. 버퍼에 있는 문자열에서 문자를 하나씩 입력 받음
        // getchar() 사용
    2. 숫자가 아닌 문자(+,-,\n)가 나올때까지 tmp배열에 저장
        // 문자가 나올경우 이전까지의 tmp 배열 값들을 정수로 변환하여 value에 저장 (atoi 사용)
    3. sum에 value를 더할지 뺄지 결정하기 위한 변수 now 사용, now의 값이 +면 더하고, -면 뺀다
        // now가 MINUS인 경우 > - 부호의 괄호 속의 값 > sum = sum - value
        // -(A), -(A + B) > A와 B 연산시 now의 값은 모두 MINUS
        // (사실상 첫 - 부호 이후의 값들은 모두 빼기 연산일것)
    4. 현재의 value다음의 문자열을 검사하여 다시 now의 값을 지정한다.
    5. 2~4의 과정을 \n이 나올때까지 반복 
        // (숫자 부호)의 묶음으로 인식하는 과정을 반복
*/

#include <stdio.h>
#include <ctype.h> //10진수면 TRUE를 반환하는 int isdigit(int c)
#include <stdlib.h>

#define PLUS    43 //문자 '+'의 아스키 코드는 43
#define MINUS   45 //문자 '-'의 아스키 코드는 45
void reset(char list[6]); //값이 입력된 (사용중인) 배열을 0으로 다시 초기화 시키기 위한 함수

int main(void)
{
    //버퍼에 있는 문자열에서 문자 하나씩 입력 받음 >> 변수 c(문자 하나)를 배열 tmp에 저장
    int sum = 0, value = 0, now = PLUS, i = 0; 
    char c;
    char tmp[6] = { 0, };

    while (1) {
        c = getchar();
        if (c == '\n')
        { //프로그램 종료 경우
            value = atoi(tmp); //값 저장
            if (now == PLUS) sum = sum + value;
            else sum = sum - value;
            break;
        }
        else if (!isdigit(c)) {//입력된 문자가 숫자가 아닐 경우 > 부호일 경우
            value = atoi(tmp); //값 저장
            i = 0; //배열 초기화를 위한 변수 초기화
            reset(tmp); //배열 초기화
            if (now == PLUS)
                sum = sum + value;
            else
                sum = sum - value;
            if (c == MINUS) now = MINUS; //-가 입력되면 그 이후로 모두 -연산일것
        }
        else { //문자가 입력되지 않았고, 계속 숫자를 입력받는 경우
            tmp[i] = c;
            i++;
        }
    }
    printf("%d", sum);
    return 0;
}

void reset(char list[6])
{
    for (int i = 0; i < 6; i++)
        list[i] = 0;
}