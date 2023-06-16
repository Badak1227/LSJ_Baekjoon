#include <stdio.h>

int main() {
	int N;
	long long stair[2][10] = { {0, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int cur = i % 2, next = (i + 1) % 2;

		stair[next][0] = stair[cur][1] % 1000000000;
		stair[next][9] = stair[cur][8] % 1000000000;

		for (int j = 1; j < 9; j++) {
			stair[next][j] = (stair[cur][j - 1] + stair[cur][j + 1]) % 1000000000;
		}
	}

	int cur = (N - 1) % 2;
	long long answer = 0;

	for (int i = 0; i < 10; i++) {
		answer = (answer + stair[cur][i]) % 1000000000;
	}

	printf("%lld", answer);
}