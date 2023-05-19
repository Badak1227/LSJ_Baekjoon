#include <stdio.h>

int main() {
	int max, sum, n;
	scanf("%d", &n);

	scanf("%d", &sum);
	max = sum;

	for (int i = 1; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp + sum < tmp) {
			sum = tmp;
		}
		else {
			sum = tmp + sum;
		}

		max = sum > max ? sum : max;
	}

	printf("%d", max);
}