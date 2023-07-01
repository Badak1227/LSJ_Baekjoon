#include <stdio.h>

int queue[10000000][2] = { 0 }, front = 0, rear = 0;

int tomato[1000][1000] = { 0 };

void enqueue(int row, int col) {
	queue[rear][0] = row;
	queue[rear][1] = col;
	rear = (rear + 1) % 1000000;

	tomato[row][col] = 1;
}

void dequeue() {
	front = (front + 1) % 1000000;
}

int main() {
	int M, N, cnt = 0, len = 0, ans = 0;

	scanf("%d %d", &M, &N);

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {

			scanf("%d", &tomato[j][k]);

			if (tomato[j][k] == 0) {
				cnt++;
			}
			else if (tomato[j][k] == 1) {
				enqueue(j, k);
				len++;
			}
		}
	}

	if (cnt == 0) {
		printf("0");

		return 0;
	}

	while (len) {
		int tmplen = 0;

		while (len--) {
			int row = queue[front][0], col = queue[front][1];

			dequeue();

			if (row + 1 < N) {
				if (tomato[row + 1][col] == 0) {

					enqueue(row + 1, col);
					cnt--;
					tmplen++;
				}
			}

			if (col + 1 < M) {
				if (tomato[row][col + 1] == 0) {

					enqueue(row, col + 1);
					cnt--;
					tmplen++;
				}
			}

			if (row - 1 >= 0) {
				if (tomato[row - 1][col] == 0) {

					enqueue(row - 1, col);
					cnt--;
					tmplen++;
				}
			}

			if (col - 1 >= 0) {
				if (tomato[row][col - 1] == 0) {

					enqueue(row, col - 1);
					cnt--;
					tmplen++;
				}
			}
		}

		len = tmplen;
		ans++;
	}

	if (cnt == 0) {
		printf("%d", ans - 1);
	}
	else {
		printf("-1");
	}
}