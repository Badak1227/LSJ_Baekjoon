#define max(x, y) x > y ? x : y
#include <stdio.h>

int main() {
	char A[1001] = { 0 }, B[1001] = { 0 };
	int dp[2][1001] = { 0 };
	scanf("%s", A);
	scanf("%s", B);

	int i = 0, j = 0;
	for (i; B[i] != 0; i++) {
		for (j = 0; A[j] != 0; j++) {
			if (B[i] == A[j]) dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
			else dp[(i + 1) % 2][j + 1] = max(dp[(i + 1) % 2][j], dp[i % 2][j + 1]);
		}
	}

	printf("%d", dp[i % 2][j]);
}