#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct dslr {
	int prev_num;
	char cur_dslr;
}dslr;

dslr visited[10000] = { 0 };
int num_queue[10000] = { 0 }, bot = 0, top = 0, point = 0;
char print_stack[10000] = { 0 };

void push(int cur_num, char dslr, int prev_num) {
	if (visited[cur_num].cur_dslr != 0) return;

	num_queue[top] = cur_num;
	visited[cur_num].cur_dslr = dslr;
	visited[cur_num].prev_num = prev_num;

	top = (top + 1) % 10000;
}

int bfs(int start, int target) {
	int res = 0;

	push(start, 0, 1);

	while (1) {
		int now_num = num_queue[bot];
		int next_num = 0;

		bot = (bot + 1) % 10000;

		//D
		next_num = now_num * 2 % 10000;

		push(next_num, 'D', now_num);
		
		if (next_num == target) break;

		//S
		next_num = now_num == 0 ? 9999 : now_num - 1;

		push(next_num, 'S', now_num);
		
		if (next_num == target) break;

		int now_digit = 0; //자릿수

		for (int i = now_num; i > 0; i = i / 10) {
			now_digit++;
		}

		//L
		int tmp = 0;

		if (now_digit == 4) {
			tmp = now_num - now_num % 1000;
			next_num = (now_num - tmp) * 10 + tmp / 1000;
		}
		else {
			next_num = now_num * 10;
		}

		push(next_num, 'L', now_num);

		if (next_num == target) break;

		//R
		tmp = now_num % 10;
		next_num = now_num / 10 + tmp * 1000;

		push(next_num, 'R', now_num);

		if (next_num == target) break;
	}

	int search = target;

	while (search != start) {
		print_stack[point++] = visited[search].cur_dslr;

		search = visited[search].prev_num;
	}

	while(point != 0) {
		printf("%c", print_stack[point-1]);
		point--;
	}
	printf("\n");

	top = 0;
	bot = 0;

	for (int i = 0; i < 10000; i++) {
		visited[i].cur_dslr = 0;
		visited[i].prev_num = 0;
	}

	return res;
}

int main() {
	int T, A, B;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int res = 0;
		scanf("%d %d", &A, &B);

		res = bfs(A, B);
	}
}