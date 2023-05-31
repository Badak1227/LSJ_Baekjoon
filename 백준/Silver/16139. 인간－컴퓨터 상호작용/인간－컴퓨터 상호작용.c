#include <stdio.h>

int main() {
	int string[2000][26] = { 0 }, N;
	char tmp;
	
	scanf("%c", &tmp);
	for (int i = 1; tmp != '\n'; i++) {

		for (int j = 0; j < 26; j++) {
			string[i][j] = string[i - 1][j];
		}

		string[i][tmp - 'a'] += 1;

		scanf("%c", &tmp);
	}
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char a;
		int l, r;
		scanf(" %c %d %d", &a, &l, &r);
		printf("%d\n", string[r + 1][a - 'a'] - string[l][a - 'a']);
	}
}