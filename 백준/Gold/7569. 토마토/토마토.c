#include <stdio.h>

int queue[1000000][3] = { 0 }, front = 0, rear = 0;

int tomato[100][100][100] = { 0 };

void enqueue(int h, int row, int col) {
	queue[rear][0] = row;
	queue[rear][1] = col;
	queue[rear][2] = h;
	rear = (rear + 1) % 1000000;

	tomato[h][row][col] = 1;
}

void dequeue() {
	front = (front + 1) % 1000000;
}

int main() {
	int M, N, H, cnt = 0, len = 0, ans = 0;

	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {

				scanf("%d", &tomato[i][j][k]);
				
				if(tomato[i][j][k] == 0){
					cnt++;
				}
				else if (tomato[i][j][k] == 1) {
					enqueue(i, j, k);
					len++;
				}
			}
		}
	}
	
	while (len) {
		int tmplen = 0;

		while (len--) {
			int row = queue[front][0], col = queue[front][1], h = queue[front][2];

			dequeue();

			if (h + 1 < H) {
				if (tomato[h + 1][row][col] == 0) {

					enqueue(h + 1, row, col);
					cnt--;
					tmplen++;
				}
			}

			if (row + 1 < N) {
				if (tomato[h][row + 1][col] == 0) {

					enqueue(h, row + 1, col);
					cnt--;
					tmplen++;
				}
			}

			if (col + 1 < M) {
				if (tomato[h][row][col + 1] == 0) {

					enqueue(h, row, col + 1);
					cnt--;
					tmplen++;
				}
			}

			if (h - 1 >= 0) {
				if (tomato[h - 1][row][col] == 0) {

					enqueue(h - 1, row, col);
					cnt--;
					tmplen++;
				}
			}

			if (row - 1 >= 0) {
				if (tomato[h][row - 1][col] == 0) {

					enqueue(h, row - 1, col);
					cnt--;
					tmplen++;
				}
			}

			if (col - 1 >= 0) {
				if (tomato[h][row][col - 1] == 0) {

					enqueue(h, row, col - 1);
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