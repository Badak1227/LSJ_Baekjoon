#include <stdio.h>

int arr[100001][2] = {0}, dp[2][3];

int max(int a, int b) {
	return a > b ? a : b;
}

int maxt(int a, int b, int c) {
	return a > max(b, c) ? a : max(b, c);
}

int main() {
	int T;

	scanf("%d", &T);

	while (T--) {
		int N;

		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i][0]);
		}

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i][1]);
		}

		dp[1][0] = arr[1][0];
		dp[1][1] = arr[1][1];
		dp[1][2] = 0;

		for (int i = 2; i <= N; i++) {
			dp[i % 2][0] = max(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]) + arr[i][0];

			dp[i % 2][1] = max(dp[(i + 1) % 2][0], dp[(i + 1) % 2][2]) + arr[i][1];

			dp[i % 2][2] = maxt(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]);
		}

		printf("%d\n", maxt(dp[N % 2][0], dp[N % 2][1], dp[N % 2][2]));
	}
}