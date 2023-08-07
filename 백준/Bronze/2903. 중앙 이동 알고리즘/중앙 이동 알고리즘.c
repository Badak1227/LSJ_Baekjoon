#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    // 중앙 이동 횟수는 (2^n + 1)^2 이다.
    int moves = pow(2, n) + 1;
    int result = moves * moves;

    printf("%d\n", result);

    return 0;
}
