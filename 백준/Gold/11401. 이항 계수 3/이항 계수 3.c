#define _CRT_SECURE_NO_WARNINGS
#define perma 1000000007
#include <stdio.h>

long long modulo_u(int n, int k) {
	long long res = 1;

	for (int i = n; i > n - k; i--) {
		res = (res * i) % perma;
	}
	
	return res;
}

long long modulo_d(int k) {
	long long res = 1;

	for (int i = k; i > 0; i--) {
		res = (res * i) % perma;
	}
	
	return res;
}

long long modulo_div(int d, int exp) {
	if (exp == 1) return d;

	int mid = exp / 2;

	long long n, res;

	n = modulo_div(d, mid);
	if (exp % 2 == 1) res = (n % perma) * (n * d % perma) % perma;
    else res = (n % perma) * (n % perma) % perma;

	return res;
}

int main() {

	int N, K;
	long long d, n1, n2, res;

	scanf("%d %d", &N, &K);
	
	d = modulo_d(K);

	n1 = modulo_u(N, K);

	n2 = modulo_div(d, perma - 2);

	res = (n1 % perma) * (n2 % perma) % perma;
	printf("%lld",res);
}