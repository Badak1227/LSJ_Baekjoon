#include <stdio.h>

void swap(int* num1, int* num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int gcd(int num1, int num2) {
	if (num1 == 0) return num2;

	return gcd(num2 % num1, num1);
}

int main() {
	int T;

	scanf("%d", &T);

	while (T--) {
		int M, N, x, y, lcm, ans = -1;

		scanf("%d %d %d %d", &M, &N, &x, &y);

		if (M < N) {
			swap(&M, &N);
			swap(&x, &y);
		}

		if (y == N) y = 0;

		lcm = M * N / gcd(N, M);

		for (int i = x; i <= lcm; i += M) {
			if (i % N == y) {
				ans = i;
				break;
			}
		}

		printf("%d\n", ans);
	}
}