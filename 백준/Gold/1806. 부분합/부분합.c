#include <stdio.h>

int main() {
	int N, S, num[100001] = { 0 };

	scanf("%d %d", &N, &S);

	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);

		num[i] = tmp + num[i - 1];
	}

	int len = N + 1;
	int l = 0, r = 1;
	while (l < N && r <= N) {
		if (num[r] - num[l] < S) {
			r++;
		}
		else {

			if (r - l < len) {
				len = r - l;
			}

			l++;
		}
	}

	if (len == N + 1) {
		printf("0");
	}
	else {
		printf("%d", len);
	}
}