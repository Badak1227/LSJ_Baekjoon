#include <stdio.h>

int deque[10001] = { 0 };

int front = 0;

int back = 0;

int size = 0;

void push_front(int num) {
	front = front - 1 < 0 ? 10000 : front - 1;
	deque[front] = num;
	size++;
}

void push_back(int num) {
	deque[back] = num;
	back = (back + 1) % 10001;
	size++;
}

void pop_front() {
	if (size == 0) {
		printf("-1\n");
        return;
	}

	printf("%d\n", deque[front]);
	front = (front + 1) % 10001;
	size--;
}

void pop_back() {
	if (size == 0) {
		printf("-1\n");
        return;
	}
	back = back - 1 < 0 ? 10000 : back - 1;
	printf("%d\n", deque[back]);
	size--;
}

void pfront() {
	if (size == 0) {
		printf("-1\n");
        return;
	}

	printf("%d\n", deque[front]);
}

void pback() {
	if (size == 0) {
		printf("-1\n");
        return;
	}
	int tmp = back - 1 < 0 ? 10000 : back - 1;
	printf("%d\n", deque[tmp]);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char str[11] = { 0 };
		int num;
		scanf("%s", str);
		switch (str[1]){
			case 'u':
				if (str[5] == 'f') {
					scanf("%d", &num);
					push_front(num);
				}
				else {
					scanf("%d", &num);
					push_back(num);
				}
				break;
			case 'o':
				if (str[4] == 'f') {
					pop_front();
				}
				else {
					pop_back();
				}
				break;
			case 'i':
				printf("%d\n", size);
				break;
			case 'm':
				printf("%d\n", size == 0 ? 1 : 0);
				break;
			case 'r':
				pfront();
				break;
			case 'a':
				pback();
				break;
		}
	}
}
