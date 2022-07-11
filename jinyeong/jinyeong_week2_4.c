// BOJ 1541 : "잃어버린 괄호"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char expression[51], temp[6] = {0}, operator = '+';
    int sum = 0;
    gets_s(expression, sizeof(expression));
    for (int i = 0; i < strlen(expression); ++i) {
        if (expression[i] == '+') {
            if (operator == '+') sum += atoi(temp);
            else if (operator == '-') sum -= atoi(temp);
            memset(temp, 0, 6 * sizeof(char));
        } else if (expression[i] == '-') {
            if (operator == '+') sum += atoi(temp);
            else if (operator == '-') sum -= atoi(temp);
            operator = '-';
            memset(temp, 0, 6 * sizeof(char));
        } else strcat(temp, expression + i);
    }
    printf("%d", sum);
    return 0;
}

