#include <stdio.h>

void print(int N,int M, int idx, int cnt, int arr[]) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < N - M + cnt + 1; i++) {
		arr[cnt] = i + 1;

		print(N, M, i + 1, cnt + 1, arr);
	}

}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	int arr[8] = { 0 };
	print(N, M, 0, 0, arr);
}