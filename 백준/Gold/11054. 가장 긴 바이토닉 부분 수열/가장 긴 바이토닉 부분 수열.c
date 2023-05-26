#include <stdio.h>

void rbsearch(int A[], int rdp[], int start, int* end, int idx) {
	int l = start, r = *end;

	while (l <= r) {
		int m = (l + r) / 2;

		if (A[idx] < rdp[m]) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	rdp[l] = A[idx];

	*end = l > *end ? l : *end;
}

int lbsearch(int A[], int ldp[], int start, int* end, int idx, int N) {
	int l = start, r = *end, rmax = 0, rdp[1000] = { 0 };

	while (l <= r) {
		int m = (l + r) / 2;

		if (A[idx] > ldp[m]) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	ldp[l] = A[idx];
	*end = l > *end ? l : *end;

	
	rdp[0] = ldp[l];
	for (int i = idx; i < N; i++) {
		rbsearch(A, rdp, 0, &rmax, i);
	}

	return *end + rmax + 1;
}

int main() {
	int N, A[1000] = { 0 }, dp[1000] = { 0 }, lmax = 0, answer = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
    
    if (N == 1) {
		printf("1");
		return 0;
	}
    
	dp[0] = A[0];
	for (int i = 0; i < N; i++) {
		int tmp = lbsearch(A, dp, 0, &lmax, i, N);
		if (tmp > answer) answer = tmp;
	}

	printf("%d", answer);
}