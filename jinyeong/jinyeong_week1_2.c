#include <stdio.h>
#include <string.h>

int main(void) {
    char string[101], cmp[101];
    int i;
    gets(string);

    for (i = strlen(string) - 1; i >= 0; --i) {
        cmp[strlen(string) - 1 - i] = string[i];
    }
    cmp[strlen(string)] = '\0';

    if (!strcmp(string, cmp)) printf("1");
    else printf("0");
}
