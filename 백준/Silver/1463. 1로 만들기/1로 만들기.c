#include <stdio.h>

int main() {
	int num[1000001] = { 0 };

	int purpose;

	scanf("%d", &purpose);

	num[1] = 0;
	for (int i = 1; i < purpose; i++) {
		int cnt = num[i];
		if (num[i + 1] == 0 || num[i + 1] > cnt + 1) {
			num[i + 1] = cnt + 1;
		}

		if (i*2 <= purpose && (num[i * 2] == 0 || num[i * 2] > cnt + 1)) {
			num[i * 2] = cnt + 1;
		}
		if (i*3 <= purpose && (num[i * 3] == 0 || num[i * 3] > cnt + 1)) {
			num[i * 3] = cnt + 1;
		}
	}

	printf("%d", num[purpose]);
}