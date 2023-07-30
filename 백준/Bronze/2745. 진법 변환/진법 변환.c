#include <stdio.h>
#include <string.h>

int charToNum(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    char str[100];
    int B;
    int result = 0;

    scanf("%s %d", str, &B);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        int num = charToNum(str[i]);
        result += num * power(B, len - i - 1);
    }

    printf("%d\n", result);

    return 0;
}
