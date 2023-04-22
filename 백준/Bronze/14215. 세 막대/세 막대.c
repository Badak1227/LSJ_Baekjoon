#include <stdio.h>

int main() {
	int num[3];
	scanf("%d %d %d", &num[0], &num[1], &num[2]);

	int max_i = 0;
	for (int i = 0; i < 3; i++) {
		max_i = num[i] > num[max_i] ? i : max_i;
	}

	int sum = 0;
	for (int i = 0; i < 3; i++) {
		if (i == max_i) continue;
		sum += num[i];
	}

	if (num[max_i] >= sum) {
		printf("%d", sum + sum - 1);
	}
	else {
		printf("%d", sum + num[max_i]);
	}
}
