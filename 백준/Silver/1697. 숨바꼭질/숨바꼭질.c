#include <stdio.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int sol(int N, int K) {
	if (K <= N) {
		return N - K;
	}
	else if (K == 1) {
		return 1;
	}
	else if (K % 2 == 1) {
		return 1 + min(sol(N, K - 1), sol(N, K + 1));
	}
	else {
		return min(K - N, 1 + sol(N, K / 2));
	}
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d", sol(N, K));
}