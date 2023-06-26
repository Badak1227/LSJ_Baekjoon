#include <stdio.h>

int sol2(int cabbage[][51], int row, int column) {

	if (cabbage[row][column] == 0 || row < 0 || column < 0) return;

	cabbage[row][column] = 0;

	sol2(cabbage, row + 1, column);
	
	sol2(cabbage, row, column + 1);

	sol2(cabbage, row - 1, column);

	sol2(cabbage, row, column - 1);
}

void sol(int M, int N, int K) {
	int row, column, cabbage[51][51] = {0}, cnt = 0;

	while (K--) {
		scanf("%d %d", &column, &row);
        
		cabbage[row][column] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
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