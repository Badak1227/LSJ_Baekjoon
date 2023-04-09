#include <stdio.h>

int fac(int num) {
    int tmp = 1;
    for (int i = 2; i <= num; i++) {
        tmp *= i;
    }
    return tmp;
}

int main() {
    int n, m, result = 1;
    scanf("%d %d", &n, &m);
    result = fac(n) / fac(m) / fac(n - m);
    printf("%d", result);
}