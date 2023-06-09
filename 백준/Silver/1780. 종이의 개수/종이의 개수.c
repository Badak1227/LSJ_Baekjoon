#include <stdio.h>

int answer[3] = { 0 };

int n;

void solution(int arr[][2188], int x1, int y1, int x2, int y2) {

	int area = (x2 - x1) * (y2 - y1);
	int sum = arr[y2][x2] - arr[y2][x1] - arr[y1][x2] + arr[y1][x1];
	
	if (sum == area * n) {
		answer[0]++;
	}
	else if (sum == 0) {
		answer[1]++;
	}
	else  if (sum == area) {
		answer[2]++;
	}
	else {
		solution(arr, x1, y1, x1 + (x2 - x1) / 3, y1 + (y2 - y1) / 3);
		solution(arr, x1 + (x2 - x1) / 3, y1, x1 + (x2 - x1) * 2 / 3, y1 + (y2 - y1) / 3);
		solution(arr, x1 + (x2 - x1) * 2 / 3, y1, x2, y1 + (y2 - y1) / 3);

		solution(arr, x1, y1 + (y2 - y1) / 3, x1 + (x2 - x1) / 3, y1 + (y2 - y1) * 2 / 3);
		solution(arr, x1 + (x2 - x1) / 3, y1 + (y2 - y1) / 3, x1 + (x2 - x1) * 2 / 3, y1 + (y2 - y1) * 2 / 3);
		solution(arr, x1 + (x2 - x1) * 2 / 3, y1 + (y2 - y1) / 3, x2, y1 + (y2 - y1) * 2 / 3);

		solution(arr, x1, y1 + (y2 - y1) * 2 / 3, x1 + (x2 - x1) / 3, y2);
		solution(arr, x1 + (x2 - x1) / 3, y1 + (y2 - y1) * 2 / 3, x1 + (x2 - x1) * 2 / 3, y2);
		solution(arr, x1 + (x2 - x1) * 2 / 3, y1 + (y2 - y1) * 2 / 3, x2, y2);
	}
}

int main() {
	int arr[2188][2188] = { 0 };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			scanf("%d", &tmp);

			if (tmp == -1) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + n;
			}
			else {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + tmp;
			}
		}
	}

	solution(arr, 0, 0, n, n);

	printf("%d\n%d\n%d", answer[0], answer[1], answer[2]);
}