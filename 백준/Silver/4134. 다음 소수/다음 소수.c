#include <stdio.h>

int is_prime(unsigned int num) { // 소수 판별 함수
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;
    unsigned int num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%u", &num);
        while (1) {
            if (is_prime(num)) {
                printf("%u\n", num);
                break;
            }
            num++;
        }
    }
    return 0;
}
