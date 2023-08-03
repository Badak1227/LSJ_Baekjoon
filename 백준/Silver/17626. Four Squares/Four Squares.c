#include <stdio.h>

int dp[50001] = { 0 };

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;

	scanf("%d", &n);

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = 5;

		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[n]);
}