#include <stdio.h>

int dp[100001] = { 1, 0 };

int main() {
	int coin[100] = { 0 }, n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d", dp[k]);
}