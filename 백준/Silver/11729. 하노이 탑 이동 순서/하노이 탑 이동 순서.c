#include <stdio.h>

void hanoi(int n, int start, int to, int bypass) {
	if (n == 1) {
		printf("%d %d\n", start, to);
	}
	else {
		hanoi(n - 1, start, bypass, to); // n-1개를 start 에서 bypass로 옮기는 단계
		printf("%d %d\n", start, to); // start의 가장 밑 원반을 to로 옮기는 단계
		hanoi(n - 1, bypass, to, start); // n-1개를 bypass에서 to로 옮기는 단계  
	}
}

int main() {
	int N, count = 1;

	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		count *= 2;
	}

	printf("%d\n", count - 1); // 2^(n+1) -1

	hanoi(N, 1, 3, 2);
}