#include <stdio.h>

char set[3] = { 0 };

void add(int x) {
	int idx = x / 8, bidx = x % 8;
	
	set[idx] |= 1 << bidx;
}

void delete(int x) {
	int idx = x / 8, bidx = x % 8;

	set[idx] &= ~(1 << bidx);
}

void check(int x) {
	int idx = x / 8, bidx = x % 8;

	if (set[idx] & (1 << bidx)) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

void toggle(int x) {
	int idx = x / 8, bidx = x % 8;

	if (set[idx] & (1 << bidx)) {
		set[idx] &= ~(1 << bidx);
	}
	else {
		set[idx] |= 1 << bidx;
	}
}

void all() {
	for (int i = 0; i < 3; i++) {
		set[i] = ~0;
	}
}

void empty() {
	for (int i = 0; i < 3; i++) {
		set[i] = 0;
	}
}

int main() {
	int T;

	scanf("%d", &T);
	
	while (T--) {
		char oper[7] = { 0 };
		int x;

		scanf("%s", oper);

		switch (oper[1]) {

		case 'd':
			scanf("%d", &x);
			add(x);
			break;
			
		case 'e':
			scanf("%d", &x);
			delete(x);
			break;
			
		case 'h':
			scanf("%d", &x);
			check(x);
			break;

		case 'o':
			scanf("%d", &x);
			toggle(x);
			break;

		case 'l':
			all();
			break;

		case 'm':
			empty();
			break;

		}
	}
}