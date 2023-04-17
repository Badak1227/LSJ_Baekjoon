#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int i = 1;
	while (i < N) {
		i <<= 1;
	}
	printf("%d", N + N - i);
}