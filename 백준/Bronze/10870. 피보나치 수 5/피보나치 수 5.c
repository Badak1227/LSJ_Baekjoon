#include <stdio.h>

int piv(int n) {
	int arr[3] = { 0, 1, 1 };
	for (int i = 2; i <= n; i++){
		int tmp1, tmp2;
		tmp1 = arr[(i - 1) % 3];
		tmp2 = arr[(i - 2) % 3];
		arr[i % 3] = tmp1 + tmp2;
	}
	printf("%d", arr[n % 3]);
}

int main() {
	int N;
	scanf("%d", &N);
	piv(N);
}