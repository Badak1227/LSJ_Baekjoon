#include <stdio.h>
#include <stdlib.h>

void sort(int start, int end, int x[], int y[]) {
    int s = start, e = end, p = x[(start + end) / 2];

    while (s <= e) {
        while (x[s] < p)
            s++;
        while (p < x[e])
            e--;

        int temp = 0;
        if (s <= e) {
            temp = x[s];
            x[s] = x[e];
            x[e] = temp;

            temp = y[s];
            y[s] = y[e];
            y[e] = temp;

            s++;
            e--;
        }
    }
    if (start < e) {
        sort(start, e, x, y);
    }
    if (s < end) {
        sort(s, end, x, y);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int* num;
    num = malloc(N * sizeof(int));

    int* rank;
    rank = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
        rank[i] = i;
    }

    sort(0, N - 1, num, rank);

    int count = 0;
    int ranking = 0;
    for (int i = 0; i < N; i++) {
        if (num[i] != num[i + 1]) {
            for (int j = count; j <= i; j++) {
                num[j] = ranking;
            }
            ranking++;
            count = i + 1;
        }
    }

    sort(0, N - 1, rank, num);

    for (int i = 0; i < N; i++) {
        printf("%d ", num[i]);
    }
}