#include <stdio.h>

int n[100000] = { 0 };
int m[100000] = { 0 };

void sort(int start, int end) {
    int l = start, r = end, mid = n[(l + r) / 2];

    while (l <= r) {
        while (n[l] < mid) {
            l++;
        }
        while (n[r] > mid) {
            r--;
        }

        if (l <= r) {
            int tmp = n[l];
            n[l] = n[r];
            n[r] = tmp;

            l++;
            r--;
        }
    }

    if (start < r) {
        sort(start, r);
    }
    if (l < end) {
        sort(l, end);
    }
}

int lower(int num, int start, int end) {
    int l = start, r = end;
    while (l < r) {
        int mid = (l + r) / 2;

        if (n[mid] < num) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return l;
}

int main() {
    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
    sort(0, N - 1);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &m[i]);
    }

    for (int i = 0; i < M; i++) {
        int lb = lower(m[i], 0, N - 1);

        printf("%d\n", n[lb] == m[i] ? 1 : 0);
    }
}