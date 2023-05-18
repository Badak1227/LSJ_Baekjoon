#include <stdio.h>

int main() {
	int T;

	scanf("%d", &T);

	long long num[100] = { 0 };
	num[0] = num[1] = num[2] = 1;
	num[3] = num[4] = 2;

	int idx = 5;

	while (T--)	{
		int N;
		scanf("%d", &N);
		
		if (num[N - 1] != 0) {
			printf("%lld\n", num[N - 1]);
		}
		else {
			for (idx; idx < N; idx++) {
				num[idx] = num[idx - 5] + num[idx - 1];
			}
			printf("%lld\n", num[N - 1]);
		}
	}

	return 0;
}