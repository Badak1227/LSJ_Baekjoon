#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int arr[500][500] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			arr[i - 1][j] += arr[i][j] > arr[i][j + 1] ? arr[i][j] : arr[i][j + 1];
		}
	}

	printf("%d", arr[0][0]);
}