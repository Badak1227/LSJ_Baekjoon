#include <stdio.h>
#include <stdlib.h>

int compare(int* num1, int* num2) {
	return *num1 - *num2;
}

int main() {
	int N, num[100000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	qsort(num, N, sizeof(int), compare);

	int l = 0, r = N - 1, answer[3] = { 0, N - 1, 2000000000 };
	while (l < r) {
		int sum = num[l] + num[r], abs;
		abs = sum < 0 ? -sum : sum;

		if(abs < answer[2]) {
			answer[0] = l;
			answer[1] = r;
			answer[2] = abs;
		}

		if (sum < 0) {
			l++;
		}
		else if (sum > 0) {
			r--;
		}
		else {
			break;
		}
	}

	printf("%d %d", num[answer[0]], num[answer[1]]);
}