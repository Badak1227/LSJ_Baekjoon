#include <stdio.h>

int main() {
	char deck[100002][4] = { 0 };

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int start = 1;
		int end = 1;
		int error = 0;
		int direction = 1;

		char str[100001] = { 0 };
		scanf("%s", str);

		int N;
		scanf("%d", &N);

		for (int j = 0; j < N; j++) {
			scanf("%*[^0-9] %[0-9]", deck[end++]);
		}
		scanf("%s", deck[0]);

		for (int i = 0; str[i] != 0 && error == 0; i++) {
			int tmp;

			switch (str[i]) {
			case 'R':
				tmp = start;
				start = end - direction;
				end = tmp - direction;
				direction *= -1;
				break;
			case 'D':
				if (start == end) {
					error = 1;
					break;
				}
				start += direction;
				break;
			}
		}

		if (error) {
			printf("error\n");
		}
		else {
			printf("[");
			while (end != start) {
				printf("%s", deck[start]);
				if (end - start != direction) {
					printf(",");
				}
				start += direction;
			}
			printf("]\n", deck[start]);
		}

	}
}