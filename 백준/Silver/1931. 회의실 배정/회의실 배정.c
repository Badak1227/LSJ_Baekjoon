#include <stdio.h>
#include <stdlib.h>

int num[100000][2] = { 0 };

int compare(int* num1, int* num2) {
    return num1[1] - num2[1];
}

int compare2(int* num1, int* num2) {
    return num1[0] - num2[0];
}

int main() {
    int N, ans;

    scanf("%d", &N);

    ans = N;

    for (int i = 0; i < N; i++) {
        
        scanf("%d %d", &num[i][0], &num[i][1]);
    }

    qsort(num, N, sizeof(int) * 2, compare);

    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (num[i - 1][1] != num[i][1]) {
            qsort(num + i - cnt, cnt, sizeof(int) * 2, compare2);
            cnt = 1;
        }
        else cnt++;
    }

    qsort(num + N - cnt, cnt, sizeof(int) * 2, compare2);

    for (int i = 1; i < N; i++) {
        if (num[i][0] == num[i][1]) continue;

        if (num[i][0] < num[i - 1][1]) {
            num[i][1] = num[i - 1][1];
            ans--;
        }
    }

    printf("%d", ans);
}