#include <stdio.h>

int on = 0, off = 0;

void solution(int arr[][129], int x1, int y1, int x2, int y2) {
	

	int area = (x2 - x1) * (y2 - y1);
	int sum = arr[y2][x2] - arr[y2][x1] - arr[y1][x2] + arr[y1][x1];

	if (sum == 0) {
		off++;
	}
	else  if (sum == area) {
		on++;
	}
	else {
		solution(arr, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2); // 2사분면
		solution(arr, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2); // 4사분면
		solution(arr, (x1 + x2) / 2, y1, x2, (y1 + y2) / 2); // 1사분면
		solution(arr, x1, (y1 + y2) / 2, (x1 + x2) / 2, y2); // 3사분면
	}
}

int main() {
	int n, arr[129][129] = { 0 };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + tmp;
		}
	}

	solution(arr, 0, 0, n, n);

	printf("%d\n%d", off, on);
}