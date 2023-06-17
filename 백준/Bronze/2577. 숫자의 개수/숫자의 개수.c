#include <stdio.h>

int main() {
	int nums[10] = { 0 }, num, A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	num = A * B * C;

	while (num > 0) {
		nums[num % 10]++;
		num /= 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", nums[i]);
	}
}