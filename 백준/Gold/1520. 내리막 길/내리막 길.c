#include <stdio.h>

int M, N, map[501][501] = { 0 }, dp[501][501] = { 0 }, cnt = 0, movement[2][4] = { {1,-1,0,0},{0,0,1,-1} };

int sol(int row, int col) {

	if (row == M && col == N) {

		return 1;
	}

	if (dp[row][col] != -1) return dp[row][col];

	dp[row][col] = 0;

	for (int i = 0; i < 4; i++) {
		int x = col + movement[0][i];
		int y = row + movement[1][i];

		if (1 <= x && x <= N && 1 <= y && y <= M) {
			if (map[y][x] < map[row][col]) {
				dp[row][col] += sol(y, x);
			}
		}
	}

	return dp[row][col];
}

int main() {

	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	sol(1, 1);

	printf("%d", dp[1][1]);
}