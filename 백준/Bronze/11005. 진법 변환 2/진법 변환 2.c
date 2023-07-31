#include <stdio.h>

char digits[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convertToBase(int num, int base) {
    if (num == 0) {
        return;
    }
    convertToBase(num / base, base);
    putchar(digits[num % base]);
}

int main() {
    int N, B;
    scanf("%d %d", &N, &B);

    convertToBase(N, B);
    putchar('\n');

    return 0;
}