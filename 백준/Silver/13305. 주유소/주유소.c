#include <stdio.h>

int main() {
	int city[100000] = { 0 }, road[99999] = { 0 }, N, cost = 0, price = 0;

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &road[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &city[i]);
	}

	price = city[0];

	for (int i = 0; i < N - 1; i++) {
		cost += price * road[i];

		if (city[i] > city[i + 1]) {
			price = city[i + 1];
		}
	}

	printf("%d", cost);
}