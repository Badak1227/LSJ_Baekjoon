#include <stdio.h>

long long N, target[2][2] = { {1,1}, {1,0} }, base[2][2] = { {1,1}, {1,0} };

void multi(long long rc[][2], long long base[][2]) {

	long long res[2][2] = { 0 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long sum = 0;
			for (int k = 0; k < 2; k++) {
				sum += rc[i][k] * base[k][j];
			}
			res[i][j] = sum;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			target[i][j] = res[i][j] % 1000000;
		}
	}
}

void sol(long long K) {
	if (K == 1) {
		return;
	}

	sol(K / 2);

	multi(target, target);

	if (K % 2 == 1) {
		multi(target, base);
	}
}

int main() {

	scanf("%lld", &N);

	sol(N + 1);

	printf("%lld", target[1][1]);
}