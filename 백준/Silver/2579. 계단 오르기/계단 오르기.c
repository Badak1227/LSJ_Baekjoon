#include <stdio.h>

int main() {
	int T;
	int arr[1001] = {0};

	scanf("%d", &T);
	
	for (int i = 1; i <= T; i++) {
		scanf("%d", &arr[i]);
	}

	int sum[1001][2] = { 0 };
	sum[1][0] = arr[1];

	for (int i = 2; i <= T; i++) {
		sum[i][0] = sum[i - 2][0] > sum[i - 2][1] ? sum[i - 2][0] : sum[i - 2][1];
		sum[i][1] = sum[i - 1][0] + arr[i];
		sum[i][0] += arr[i];
	}

	int max = 0;
	for (int i = 0; i < 2; i++) {
		max = sum[T][i] > max ? sum[T][i] : max;
	}

	printf("%d", max);
}