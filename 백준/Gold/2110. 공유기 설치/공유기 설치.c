#include <stdio.h>
#include <stdlib.h>

int compare(int* num1, int* num2) {
	return *num1 > *num2 ? 1 : 0;
}

int main() {
	int N, C, min = 1, max, answer = 1;
	int houses[200000] = { 0 };

	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d", &houses[i]);
	}

	qsort(houses, N, sizeof(int), compare);

	max = houses[N - 1] - houses[0];

	min = 1;

	while (min <= max) {
        int count = C - 1, last = 0, mid = (max + min) / 2;

		for (int i = 1; i < N; i++) {
			if (houses[i] - houses[last] >= mid) {
				count--;
				last = i;
			}
		}

		if (count > 0) {
			max = mid - 1;
		}
		else {
			answer = mid;
			min = mid + 1;
		}
	}

	printf("%d", answer);
}