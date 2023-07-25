#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, N, x, y;
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int lcm_MN = lcm(M, N);
        int answer = -1;

        while (x <= lcm_MN) {
            if ((x - 1) % N + 1 == y) {
                answer = x;
                break;
            }
            x += M;
        }

        printf("%d\n", answer);
    }

    return 0;
}