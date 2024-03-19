#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int height[257] = { 0 };

int main() {
	int N, M, B, full, time = 0, blocks = 0, ans[2] = { 0 };

	scanf("%d %d %d", &N, &M, &B);

	full = N * M;

	blocks += B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int block = 0;

			scanf("%d", &block);

			blocks += block;
			time += block * 2;

			for (int k = 1; k <= block; k++) {
				height[k]++;
			}
		}
	}

	ans[0] = time;
	ans[1] = 0;

	for (int i = 1; i < 257; i++) {
		if (full > blocks) break;

		time += full - height[i] * 3;
		blocks -= full;

		if (time <= ans[0]) {
			ans[0] = time;
			ans[1] = i;
		}
	}

	printf("%d %d", ans[0], ans[1]);
}