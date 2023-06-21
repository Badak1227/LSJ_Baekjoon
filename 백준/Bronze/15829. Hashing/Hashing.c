#include <stdio.h>

int main() {
	int hash = 0, r = 1, N;
	char str[51];

	scanf("%d", &N);

	scanf("%s", str);

	for (int i = 0; i < N; i++) {
		hash += (str[i] - 'a' + 1) * r % 1234567891;
		r = (r * 31);
	}

	printf("%d", hash);
}