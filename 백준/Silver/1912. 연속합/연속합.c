#include <stdio.h>

int main() {
	int max, n;
	int num[100000] = { 0 };
	scanf("%d", &n);

	scanf("%d", &num[0]);
	max = num[0];

	for (int i = 1; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp + num[i - 1] < tmp) {
			num[i] = tmp;
		}
		else {
			num[i] = tmp + num[i-1];
		}

		max = num[i] > max ? num[i] : max;
	}

	printf("%d", max);
}