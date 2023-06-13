#include <stdio.h>

int main() {
	char str[1001] = { 0 };
	int idx;

	scanf("%s", str);

	scanf("%d", &idx);

	printf("%c", str[idx - 1]);
}