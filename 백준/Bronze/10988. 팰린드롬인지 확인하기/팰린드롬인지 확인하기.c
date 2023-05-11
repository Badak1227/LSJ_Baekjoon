#include <stdio.h>
#include <string.h>

int main() {
	char letter[100];
	int answer = 1;

	scanf("%s", letter);
	
	int len = strlen(letter);

	for (int i = 0; i < len / 2; i++) {
		if (letter[i] != letter[len - i - 1]) answer = 0;
	}

	printf("%d", answer);
}