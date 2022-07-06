#include <stdio.h>
#include <string.h>

int main(void) {
    char string[101], cmp[101]; // 입력 받은 문자열을 저장할 배열과 문자열을 거꾸로 배치하여 저장할 배열 생성
    int i;
    gets(string);

    for (i = strlen(string) - 1; i >= 0; --i) { // 입력 받은 문자열 배열을 마지막부터 순차적으로 비교할 배열 처음부터 저장
        cmp[strlen(string) - 1 - i] = string[i];
    }
    cmp[strlen(string)] = '\0';

    if (!strcmp(string, cmp)) // 팰린드롬이면 1 출력, 아니면 0 출력
        printf("1");
    else
        printf("0");
}
