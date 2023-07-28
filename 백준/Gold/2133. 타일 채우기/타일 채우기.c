#include <stdio.h>

int arr[31] = { 0 };

int main() {
	int N;

	scanf("%d", &N);

	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 3;
	arr[3] = 0;

	for (int i = 4; i <= N; i++) {
		arr[i] += arr[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			arr[i] += arr[j] * 2;
		}
	}
	
	printf("%d", arr[N]);
}