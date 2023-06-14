#include <stdio.h>

int main() {
	int K, N;
	long long LAN[10001] = { 0 }, max = 0;

	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%lld", &LAN[i]);

		max = LAN[i] > max ? LAN[i] : max;
	}

	long long l = 1, r = max, count = 0;

	while (l <= r) {
		count = 0;

		long long m = l + (r - l) / 2;

		int i = 0;
		while (LAN[i] != 0) {
			count += LAN[i++] / m;
		}

		if (count < N) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	printf("%lld", r);
}