#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct tuple {
	char url[21];
	char password[21];

}tuple;

tuple hash_table[142867] = { 0 };

int hash_fun(char str[21]) {
	int res = 0;

	for (int i = 0; str[i] != 0; i++) {
		res = ((res << 5) + res + str[i]) % 142867;
	}

	return res;
}

void put(char url[21], char password[21]) {
	int hash = hash_fun(url);
	
	while (hash_table[hash].url[0] != 0) {
		hash = (hash + 1) % 142867;
	}

	for (int i = 0; url[i] != 0; i++) {
		hash_table[hash].url[i] = url[i];
		hash_table[hash].url[i + 1] = 0;
	}
	
	for (int i = 0; password[i] != 0; i++) {
		hash_table[hash].password[i] = password[i];
		hash_table[hash].password[i + 1] = 0;
	}
}

void find(char url[21]) {
	int check = 1, hash = hash_fun(url);

	while (check) {
		check = 0;

		for (int i = 0; url[i] != 0; i++) {
			if (url[i] != hash_table[hash].url[i]) {
				hash = (hash + 1) % 142867;
				check = 1;
			}
		}
	}

	printf("%s\n", hash_table[hash].password);
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		char url[21], password[21];

		scanf("%s %s", url, password);

		put(url, password);
	}

	for (int i = 0; i < M; i++) {
		char url[21];

		scanf("%s", url);

		find(url);
	}
}