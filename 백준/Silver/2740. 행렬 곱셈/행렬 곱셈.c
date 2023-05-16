#include <stdio.h>

int main() {
	int A[100][100] = { 0 };
	int B[100][100] = { 0 };

	int N, M, K;
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	scanf("%d %d", &M, &K);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int sum = 0;
			for (int k = 0; k < M; k++) {
				sum += A[i][k] * B[k][j];
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
}