#include <stdio.h>

char str[1000001] = { 0 };


int main() {
	int N, M, cnt = 0;

	scanf("%d", &N);

	scanf("%d", &M);

	scanf("%s", str);

	for (int i = 0; i < M; i++) {
		int check = 0;

		if(str[i] == 'I') {

			for (int j = 1; j <= N; j ++) {
				if (i + j * 2 >= M ) {
					check = 1;
					break;
				}
				else if (str[i + j * 2] != 'I' || str[i + j * 2 - 1] != 'O') {
					check = 1;
					break;
				}
			}

			if (check == 0) cnt++;
		}
	}

	printf("%d", cnt);
}