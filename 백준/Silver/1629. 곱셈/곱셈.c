#include <stdio.h>

int sol(long long A, long long B, long long C) {

	if (B == 1) {
		return A % C;
	}

	long long res = sol(A, B / 2, C) % C;
	res = res * res % C;

	if (B % 2 == 0) {
		return res;
	}
	else {
		return (res * A % C) % C;
	}
}

int main() {
	long long A, B, C, res = 1;

	scanf("%lld %lld %lld", &A, &B, &C);

	printf("%lld\n", sol(A, B, C));
}