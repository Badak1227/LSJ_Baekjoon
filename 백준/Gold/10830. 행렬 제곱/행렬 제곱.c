#include <stdio.h>

int N, target[5][5] = { 0 }, base[5][5] = { 0 };

void multi(int rc[][5], int base[][5], int N) {

	int res[5][5] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				sum += rc[i][k] * base[k][j];
			}
			res[i][j] = sum;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			target[i][j] = res[i][j] % 1000;
		}
	}
}

void sol(long long K) {
	if (K == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				target[i][j] = base[i][j];
			}
		}

		return;
	}

	sol(K / 2);

	multi(target, target, N);

	if (K % 2 == 1) {
		multi(target, base, N);
	}
}

int main() {
	long long A;
	scanf("%d %lldd", &N, &A);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &base[i][j]);
		}
	}
	
	sol(A);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", target[i][j] % 1000);
		}
		printf("\n");
	}
}