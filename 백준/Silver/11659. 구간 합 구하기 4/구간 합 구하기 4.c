#include <stdio.h>

int nums[100001] = { 0 };

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		nums[i] = nums[i - 1] + num;
	}
	
	for (int i = 1; i <= M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", nums[r] - nums[l - 1]);
	}
}