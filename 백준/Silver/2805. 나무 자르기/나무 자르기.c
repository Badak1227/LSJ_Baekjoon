#include <stdio.h>

int main() {
	int N, M, max = 0,trees[1000000] = { 0 };

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &trees[i]);

		max = trees[i] > max ? trees[i] : max;
	}

	int l = 0, r = max;

	while (l <= r) {
		long long len = 0;
		int m = l + (r - l) / 2;

		for (int i = 0; i < N; i++) {
			if (trees[i] <= m) continue;

			len += trees[i] - m;
		}

		if (len < M) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	printf("%d", r);
}