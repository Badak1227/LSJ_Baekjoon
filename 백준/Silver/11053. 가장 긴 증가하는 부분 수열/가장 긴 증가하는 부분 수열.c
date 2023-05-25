#include <stdio.h>

int max = 0;

void bsearch(int A[], int start, int end, int num) {
	int l = start, r = end;

	while (l <= r) {
		int m = (l + r) / 2;

		if (num > A[m]) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	A[l] = num;
	max = l > max ? l : max;
}

int main() {
	int N, A[1000] = { 0 };
	
	scanf("%d", &N);

	scanf("%d", &A[0]);

	for (int i = 1; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		bsearch(A, 0, max, tmp);
	}

	printf("%d", max + 1);
}