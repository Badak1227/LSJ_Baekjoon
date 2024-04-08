#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct cloth_t {
	char type[21];
	char num;
}cloth_t;

cloth_t cloth_type[43] = { 0 };

char hash_fun(char type[21]) {
	char hash = 0;

	for (int i = 0; type[i] != 0; i++) {
		hash = (hash + (hash << 5)) % 43;
	}

	return hash;
}

void insert(char type[21]) {
	char hash = hash_fun(type);

	while (cloth_type[hash].num != 0) {
		int check = 1;

		for (int i = 0; type[i] != 0; i++) {
			if (cloth_type[hash].type[i] != type[i]) {
				check = 0;
				break;
			}
		}

		if (check) break;
		else hash++;
	}

	if (cloth_type[hash].num == 0) {
		int i = 0;

		for (i = 0; type[i] != 0; i++) {
			cloth_type[hash].type[i] = type[i];
		}
	}

	cloth_type[hash].num++;
}

int main() {
	int type_num[30];
	
	int T, n;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n, answer = 1;

		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			char type[21] = { 0 }, name[21] = { 0 };

			scanf("%s %s", name, type);

			insert(type);
		}

		for (int j = 0; j < 30; j++) {
			if (cloth_type[j].num != 0) {
				answer *= (cloth_type[j].num + 1);
				cloth_type[j].num = 0;
			}
		}

		printf("%d\n", answer - 1);
	}
}