#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int forbidden[10] = { 0 };

int check(int num) {
	int count = 0;

	int i = num;
	do {
		int tmp = i % 10;
        
        i = i / 10;
		count++;

		if (forbidden[tmp] == 1) return 0;
	} while (i > 0);

	return count;
}

int main() {
	int N, M, res = 0;

	scanf("%d %d", &N, &M);

	res = N - 100;
	res = res < 0 ? -res : res;

	for (int i = 0; i < M; i++) {
		int tmp;

		scanf("%d", &tmp);

		forbidden[tmp] = 1;
	}

	if (M == 10) {
		printf("%d", res);
		return 0;
	}
	
	int u_side = N, d_side = N, count = 0;
	
	while (1) {
		if (check(d_side)) {
			count += check(d_side);
			break;
		}
		else if (check(u_side)) {
			count += check(u_side);
			break;
		}

		u_side++;
		if (d_side > 0) d_side--;
		count++;
	}

	printf("%d", res < count ? res : count);
}