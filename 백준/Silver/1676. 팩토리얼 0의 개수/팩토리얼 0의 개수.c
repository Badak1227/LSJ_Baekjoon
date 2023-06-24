#include <stdio.h>

int dp[501] = { 0 };

int main() {
	int N;
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (i % 125 == 0) {
			dp[i] += 3;
		}
		else if (i % 25 == 0) {
			dp[i] += 2;
		}
		else if (i % 5 == 0) {
			dp[i] += 1;
		}

		dp[i] += dp[i - 1];
	}

	printf("%d", dp[N]);
}