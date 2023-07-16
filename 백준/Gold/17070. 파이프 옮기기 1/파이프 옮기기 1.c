#include <stdio.h>

int N, house[17][17] = { 0 }, dp[3][17][17] = { 0 }, movement[3][2] = { {1, 0}, {1, 1}, {0, 1} }, cnt = 0;

// state 0 : 가로, state 1 : 대각선, state 2 : 세로

int main() {
    
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &house[i][j]);
        }
    }

    dp[0][1][2] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            if (house[i][j] == 1) continue;

            dp[0][i][j] += dp[0][i][j - 1] + dp[1][i][j - 1];
            
            if (house[i - 1][j] == 0 && house[i][j - 1] == 0) {
                dp[1][i][j] += dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
            }
            
            dp[2][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];
        }
    }

    printf("%d", dp[0][N][N] + dp[1][N][N] + dp[2][N][N]);
}