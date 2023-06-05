#include <stdio.h>

int num[500001] = { 0 };

int main() {
	int N, prime[4000001] = { 0 };
	int end = 2;

	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		int bitidx = i % 8;
		int idx = i / 8;

		if ((num[idx] & (1 << bitidx)) == 0) {
			prime[end++] = prime[end - 1] + i;
		}

		for (int j = 2; i * j <= N; j++) {
			bitidx = (i * j) % 8;
			idx = (i * j) / 8;
			num[idx] = num[idx] | (1 << bitidx);
		}
	}

	int l = 0, r = 1, answer = 0;
	while (l < end - 1 && r < end) {
		if (prime[r] - prime[l] < N) {
			r++;
		}
		else if (prime[r] - prime[l] > N) {
			l++;
		}
		else {
			answer++;
			r++;
		}
	}

	printf("%d", answer);
}