#include <stdio.h>

int dp[41][2] = {0};

void fibonacci(int n) {
	if (n < 2) return;

	if (dp[n-1][0] == 0 && dp[n-1][1] == 0) {
		fibonacci(n - 1);
			
	}
	if (dp[n - 2][0] != 0 && dp[n - 2][1] != 0) {
		fibonacci(n - 2);
	}

	dp[n][0] = dp[n - 1][0] + dp[n - 2][0];
	dp[n][1] = dp[n - 1][1] + dp[n - 2][1];

	return;
}

int main() {
	int N;

	dp[0][0] = 1;
	dp[1][1] = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int tmp;

		scanf("%d", &tmp);

		fibonacci(tmp);

		printf("%d %d\n", dp[tmp][0], dp[tmp][1]);
	}
}