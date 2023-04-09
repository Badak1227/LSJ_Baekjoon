#include <stdio.h>

int fac(int num) {
    int tmp = 1;
    for (int i = num; i >= 2; i--) {
        tmp *= i;
    }
    return tmp;
}

int main() {
    int n, result = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        result += fac(n) / fac(i) / fac(n - i);
    }
    printf("%d", result);
}