#include <stdio.h>

int main() {
	int N, cur, next, mod = 1000000000;
	long long stair[2][10] = { {0, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} }, answer = 0;

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		cur = i % 2, next = (i + 1) % 2;

		stair[next][0] = stair[cur][1] % mod;
		stair[next][9] = stair[cur][8] % mod;

		for (int j = 1; j < 9; j++) {
			stair[next][j] = (stair[cur][j - 1] + stair[cur][j + 1]) % mod;
		}
	}
    
    cur = (N - 1) % 2;
    
	for (int i = 0; i < 10; i++) {
		answer = (answer + stair[cur][i]) % mod;
	}

	printf("%lld", answer);
}