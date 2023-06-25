#include <stdio.h>

int main() {
	char str[1001] = { 0 };
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		printf("%c", str[0]);
		for (int j = 0;; j++) {
			if (str[j] == 0) {
				printf("%c\n", str[j - 1]);
				break;
			}
		}
	}

}