#include <stdio.h>

int main() {
	int stack[10] = { 0 };
	int end = -1;
	
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &stack[i]);
		end++;
	}

	int count = 0;
	while (K > 0 && end >=0) {
		int div = K / stack[end];
		int mob = K % stack[end];

		if (div > 0) {
			count += div;
			K -= div * stack[end];
		}
		else {
			end--;
		}
	}

	printf("%d", count);
}