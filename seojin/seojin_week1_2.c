/*
    문제 10988번 [팰린드롬인지 확인하기]
    1. 단어 입력 (1이상 100이하의 길이, 알파벳 소문자로만 이루어짐)
    2. 팰린드롬인지 확인 >> 함수 사용
    3. 팰린드롬이면 1, 아니면 0 출력
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define length  100
int palindrome(char string[length]); //팰린드롬 검사 함수(맞을 경우 1, 아닐 경우 0 반환)

int main (void)
{
    char str[length];
    int i;
    scanf("%s", str);
    printf("%d", palindrome(str));
    return 0;
}

int palindrome(char string[length]) //맞을 경우 1, 아닐 경우 0 반환
{
    //가장 앞의 문자와 가장 뒤의 문자 비교 >> 거리를 좁혀가며 비교 >> 두 변수의 값이 일치하거나 front > back 인 경우 중단
    int front, back;
    front = 0;
    back = strlen(string) - 1;
    while (front < back)
    {
        if(string[front] == string[back])
        {
            front = front + 1;
            back = back - 1;
        }
        else
            return 0; //팰린드롬이 아닌 경우
    }
    return 1; // 맞는 경우
}