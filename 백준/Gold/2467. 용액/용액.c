#include <stdio.h>

int abs(int n) {
	return n < 0 ? -n : n;
}

int main() {
	int N, arr[100000] = { 0 }, ans[2] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	if (arr[0] > 0) {
		printf("%d %d", arr[0], arr[1]);
		return 0;
	}
	else if (arr[N - 1] < 0) {
		printf("%d %d", arr[N - 2], arr[N - 1]);
		return 0;
	}

	int left = 0, right = N - 1;

	while (left < right) {
		int state = arr[left] + arr[right];

		if (abs(arr[ans[0]] + arr[ans[1]]) > abs(state)) {
			ans[0] = left;
			ans[1] = right;
		}

		if (state < 0) left++;
		else if (state > 0) right--;
		else break;
	}

	printf("%d %d", arr[ans[0]], arr[ans[1]]);

	return 0;
}