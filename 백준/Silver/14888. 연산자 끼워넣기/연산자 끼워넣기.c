#define max(a, b) a>b ? a : b
#define min(a, b) a<b ? a : b
#include <stdio.h>

int max = -1000000000;
int min = 1000000000;

int operator[11] = { 0 };
int end = 0;

void exp(int nums[], int signs[], int cnt, int N) {
	if (cnt == N - 1) {
		int tmp = nums[0];

		for (int i = 1; i < N; i++) {
			if (operator[i - 1] == 0) {
				tmp = tmp + nums[i];
			}
			else if (operator[i - 1] == 1) {
				tmp = tmp - nums[i];
			}
			else if (operator[i - 1] == 2) {
				tmp = tmp * nums[i];
			}
			else if (operator[i - 1] == 3) {
				tmp = tmp / nums[i];
			}
		}

		max = max(tmp, max);
		min = min(tmp, min);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (signs[i] == 0) continue;

		signs[i]--;
		operator[cnt] = i;

		exp(nums, signs, cnt + 1, N);

		signs[i]++;
	}

}

int main() {
	int N, nums[11] = { 0 }, signs[4] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &signs[i]);
	}

	exp(nums, signs, 0, N);

	printf("%d\n%d", max, min);
}