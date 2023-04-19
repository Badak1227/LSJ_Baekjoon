#include <stdio.h>

long long int factorial(int N) {
	long long int num = 1;
	while (N) {
		num *= N--;
	}
	return num;
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%lld", factorial(N));
}
