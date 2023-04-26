#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int basket[100] = { 0 };

    for (int i = 0; i < M; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        for (int j = l - 1; j < r; j++) {
            basket[j] = k;
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", basket[i]);
    }
}