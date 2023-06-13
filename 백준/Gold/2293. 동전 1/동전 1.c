#include <stdio.h>

int dp[100001] = { 1, 0 };

void sol(int arr[], int n, int k) {
	if (k < arr[n]) return;

	sol(arr, n, k - 1);
	dp[k] += dp[k - arr[n]];
}

int main() {
	int coin[100] = { 0 }, n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	for (int j = 0; j < n; j++) {
		sol(coin, j, k);
	}

	printf("%d", dp[k]);
}