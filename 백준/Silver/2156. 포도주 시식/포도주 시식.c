#include <stdio.h>

int main() {
	int n;
	int wine[10000][3] = { 0 };

	scanf("%d", &n);

	scanf("%d", &wine[0][0]);
	scanf("%d", &wine[1][1]);
	wine[1][0] += wine[1][1] + wine[0][0];
	wine[1][2] = wine[0][0];

	for (int i = 2; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		wine[i][0] = wine[i - 1][1] + tmp;
		wine[i][1] = wine[i - 1][2] + tmp;
		wine[i][2] = (wine[i - 1][0] > wine[i - 1][1]) && (wine[i - 1][0] > wine[i - 1][2]) ? wine[i - 1][0] : (wine[i - 1][1] > wine[i - 1][2]) ? wine[i - 1][1] : wine[i - 1][2];
	}

	printf("%d", (wine[n - 1][0] > wine[n - 1][1]) && (wine[n - 1][0] > wine[n - 1][2]) ? wine[n - 1][0] : (wine[n - 1][1] > wine[n - 1][2]) ? wine[n - 1][1] : wine[n - 1][2]);
}