#include <stdio.h>

int main() {
    int N, M, arr[101] = { 0 };

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }


    while (M--) {
        int i, j, tmp = 0;

        scanf("%d %d", &i, &j);

        for (; (i + tmp) <= (i + j) / 2; tmp++) {
            int temp = arr[i + tmp];
            arr[i + tmp] = arr[j - tmp];
            arr[j - tmp] = temp;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", arr[i]);
    }
}