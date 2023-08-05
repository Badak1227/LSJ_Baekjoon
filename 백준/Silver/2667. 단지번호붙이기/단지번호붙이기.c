#include <stdio.h>
#include <stdlib.h>

int N, movement[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }, list[313] = { 0 }, end = 0;

char board[25][25] = { 0 }, estate[25][25] = { 0 };

void dfs(int x, int y) {

	list[end]++;

	estate[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextx = x + movement[i][0], nexty = y + movement[i][1];

		if (-1 < nextx && nextx < N && -1 < nexty && nexty < N) {
			if (board[nexty][nextx] == '1' && estate[nexty][nextx] == 0) {
				dfs(nextx, nexty);
			}
		}
	}

}

int compare(int* num1, int* num2) {
	return *num1 - *num2;
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (board[i][j] == '1' && estate[i][j] == 0) {
				dfs(j, i);
				end++;
			}
		}
	}

	qsort(list, end, sizeof(int), compare);

    printf("%d\n", end);
    
	for (int i = 0; i < end; i++) {
		printf("%d\n", list[i]);
	}
}