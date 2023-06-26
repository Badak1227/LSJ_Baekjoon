#include <stdio.h>

int sol2(int cabbage[][52], int row, int column) {

	cabbage[row][column] = 0;

	if (cabbage[row + 1][column] == 1) {
		sol2(cabbage, row + 1, column);
	}
	
	if (cabbage[row][column + 1] == 1) {
		sol2(cabbage, row, column + 1);
	}

	if (cabbage[row - 1][column] == 1) {
		sol2(cabbage, row - 1, column);
	}

	if (cabbage[row][column - 1] == 1) {
		sol2(cabbage, row, column - 1);
	}
}

void sol(int M, int N, int K) {
	int row, column, cabbage[52][52] = {0}, cnt = 0;

	while (K--) {
		scanf("%d %d", &column, &row);

		column++;
		row++;

		cabbage[row][column] = 1;
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			
			if (cabbage[i][j] == 1) {
				sol2(cabbage, i, j);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
}

int main() {
	int T, M, N, K;

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &M, &N, &K);

		sol(M, N, K);
	}
}