#include <stdio.h>

void quick(int group[], int start, int end) {
    int l = start, r = end, m = group[(l + end) / 2];
    while (l <= r) {
        while (group[l] < m) {
            l++;
        }
        while (group[r] > m) {
            r--;
        }

        if (l <= r) {
            int tmp = group[l];
            group[l] = group[r];
            group[r] = tmp;

            l++;
            r--;
        }
    }
    if (start < r) {
        quick(group, start, r);
    }
    if (l < end) {
        quick(group, l, end);
    }
}

int main() {
    int N, M;
    int A[200001] = { 0 }, B[200001] = { 0 };

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }

    quick(A, 0, N - 1);
    quick(B, 0, M - 1);

    int Aindex = 0, Bindex = 0, count = 0;
    while (A[Aindex] && B[Bindex]) {
        if (A[Aindex] == B[Bindex]) {
            count++;
            Aindex++;
            Bindex++;
        }
        else if (A[Aindex] > B[Bindex]) {
            Bindex++;
        }
        else {
            Aindex++;
        }
    }

    printf("%d", (N + M) - count * 2);
}