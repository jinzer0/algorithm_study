// BOJ 17609 : "회문"
#include <stdio.h>
#include <string.h>

int is_palin(char *); // 회문인지 검사하는 함수

int is_pseudo(char *, char *); // 유사 회문인지 검사하는 함수

int main(void) {
    int T;
    char string[100001];
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) { // T번 반복하여 입력을 받고 회문인지 검사
        scanf("%s", string);
        printf("%d\n", is_palin(string)); // 반환값 0 : 회문, 1 : 유사 회문, 2 : 둘 다 아님
    }
}

int is_palin(char *str) {
    char *start = str, *end = str + strlen(str) - 1;
    while (start <= end) { // 두 포인터가 엇갈리지 않을 때까지 반복
        if (*start == *end) { // 같은 문자면 포인터 증감
            start++;
            end--;
        } else if (*start != *end) { // 같지 않으면 유사 회문인지 총 두 번 검사.
            // 같지 않은 문자를 하나씩 제거하고 각각 검사해야 하므로 왼쪽 포인터는 1을 증가시키고, 오른쪽 포인터는 1 감소시켜 검사
            // 만약 둘 중 하나라도 유사 회문이면 1 반환, 둘 다 아니면 2 반환
            if (is_pseudo(start + 1, end) || is_pseudo(start, end - 1)) return 1; // 한 번은 앞의 문자를 제거하여, 다른 한 번은 뒷 문자를 제거하여 검사
            else return 2; // 유사 회문이 아니면 2 반환
        }
    }
    return 0;
}

int is_pseudo(char *start, char *end) { //
    while (start <= end) {
        if (*start == *end) {
            start++;
            end--;
        } else if (*start != *end) return 0;
    }
    return 1;
}