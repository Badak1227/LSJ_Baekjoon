#include <stdio.h>

int main() {
    int N, dp[2][2][3] = { 0 }, ans[2] = { -1, 900001 };

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int left, mid, right;
        
        scanf("%d %d %d", &dp[i % 2][0][0], &dp[i % 2][0][1], &dp[i % 2][0][2]);

        for (int j = 0; j < 3; j++) {
            dp[i % 2][1][j] = dp[i % 2][0][j];
        }

        //최댓값
        left = dp[(i + 1) % 2][0][0] > dp[(i + 1) % 2][0][1] ? dp[(i + 1) % 2][0][0] : dp[(i + 1) % 2][0][1];
        right = dp[(i + 1) % 2][0][1] > dp[(i + 1) % 2][0][2] ? dp[(i + 1) % 2][0][1] : dp[(i + 1) % 2][0][2];
        mid = left > right ? left : right;

        dp[i % 2][0][0] += left;
        dp[i % 2][0][1] += mid;
        dp[i % 2][0][2] += right;

        //최소값
        left = dp[(i + 1) % 2][1][0] < dp[(i + 1) % 2][1][1] ? dp[(i + 1) % 2][1][0] : dp[(i + 1) % 2][1][1];
        right = dp[(i + 1) % 2][1][1] < dp[(i + 1) % 2][1][2] ? dp[(i + 1) % 2][1][1] : dp[(i + 1) % 2][1][2];
        mid = left < right ? left : right;

        dp[i % 2][1][0] += left;
        dp[i % 2][1][1] += mid;
        dp[i % 2][1][2] += right;
    }

    for (int i = 0; i < 3; i++) {
        ans[0] = dp[(N - 1) % 2][0][i] > ans[0] ? dp[(N - 1) % 2][0][i] : ans[0];
    }

    for (int i = 0; i < 3; i++) {
        ans[1] = dp[(N - 1) % 2][1][i] < ans[1] ? dp[(N - 1) % 2][1][i] : ans[1];
    }

    printf("%d %d", ans[0], ans[1]);
}