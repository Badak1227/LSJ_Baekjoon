#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, answer = 0;
char board[601][601] = { 0 }, movement[4][2] = {
	{1, 0},
	{0, 1},
	{0, -1},
	{-1, 0}
};

int dfs(int y, int x) {
	if (board[y][x] == 'P') answer++;

	board[y][x] = 'X';

	for (int i = 0; i < 4; i++) {
		int next_y = y + movement[i][0], next_x = x + movement[i][1];

		if (0 > next_y || next_y >= N || 0 > next_x || next_x >= M || board[next_y][next_x] == 'X') continue;
		
		dfs(next_y, next_x);
	}
}

int main() {
	int y = 0, x = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &board[i][j]);

			if (board[i][j] == 'I') {
				y = i;
				x = j;
			}
		}
	}

	dfs(y, x);

	if (answer > 0) printf("%d", answer);
	else printf("TT");
}