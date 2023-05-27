#include <stdio.h>

void lbsearch(int dp[], int start, int* end, int num) {
	int l = start, r = *end;

	while (l <= r) {
		int m = (l + r) / 2;

		if (num > dp[m]) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	dp[l] = num;
	*end = l > *end ? l : *end;
}

int compare(int* l, int* r) {

	return l[0] - r[0];
}

int main() {
	int N, A[100][2] = { 0 }, dp[100] = { 0 }, max = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i][0], &A[i][1]);
	}
	
	qsort(A, N, sizeof(int[2]), compare);

	dp[0] = A[0][1];
	for (int i = 1; i < N; i++) {
		lbsearch(dp, 0, &max, A[i][1]);
	}

	printf("%d", N - max - 1);
}