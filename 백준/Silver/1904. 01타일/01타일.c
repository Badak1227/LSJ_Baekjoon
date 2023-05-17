#include <stdio.h>

int main() {
	int N, p1=1, p2=2;

	scanf("%d" ,&N);

	if (N < 3) {
		printf("%d", N);
		return 0;
	}

	for (int i = 3; i <= N; i++) {
		int tmp = p2;
		p2 = (p2 + p1) % 15746;
		p1 = tmp;
	}

	printf("%d", p2);
	return 0;
}