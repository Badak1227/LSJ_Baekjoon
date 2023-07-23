#include <stdio.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int sol(int N, int K) {
	if (K <= N) {
		return N - K;
	}
	//N이 0일 경우 무한루프에 빠지는 것을 방지하기 위함
	else if (K == 1) {
		return 1;
	}
	// K가 홀수일 경우
	else if (K % 2 == 1) {
		return 1 + min(sol(N, K - 1), sol(N, K + 1));
	}
	// K가 짝수일 경우
	else {
		return min(K - N, sol(N, K / 2));
	}
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d", sol(N, K));
}