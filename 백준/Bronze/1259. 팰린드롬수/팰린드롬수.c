#include <stdio.h>
#include <string.h>

int main() {
	char N[6] = { 1 };

	while (1) {
		scanf("%s", N);

		if (N[0] == '0') break;

		int len = strlen(N), answer = 1;

		for (int i = 0; i < len / 2; i++) {
			if (N[i] != N[len - i - 1]) {
				answer = 0;
				break;
			}
		}

		if (answer == 1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}