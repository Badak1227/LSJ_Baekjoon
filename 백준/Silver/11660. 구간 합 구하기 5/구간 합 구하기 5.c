#include <stdio.h>

int main() {

	int N, M, A[1025][1025] = { 0 };

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			scanf("%d", &tmp);

			A[i][j] = A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1] + tmp;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		printf("%d\n", A[y2][x2] + A[y1 - 1][x1 - 1] - A[y1 - 1][x2] - A[y2][x1 - 1]);
	}
}