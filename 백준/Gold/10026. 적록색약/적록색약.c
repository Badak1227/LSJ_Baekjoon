#include <stdio.h>

char RGB1[100][100] = { 0 }, RGB2[100][100] = { 0 };

void sol1(int i, int j, int N, char rgb) {
	RGB1[i][j] = 0;

	if (i - 1 >= 0) {
		if (RGB1[i - 1][j] == rgb) {
			sol1(i - 1, j, N, rgb);
		}
	}

	if (i + 1 < N) {
		if (RGB1[i + 1][j] == rgb) {
			sol1(i + 1, j, N, rgb);
		}
	}

	if (j - 1 >= 0) {
		if (RGB1[i][j - 1] == rgb) {
			sol1(i, j - 1, N, rgb);
		}
	}

	if (j + 1 < N) {
		if (RGB1[i][j + 1] == rgb) {
			sol1(i, j + 1, N, rgb);
		}
	}
}

void sol2(int i, int j, int N, char rgb) {
	RGB2[i][j] = 0;

	if (i - 1 >= 0) {
		if (RGB2[i - 1][j] == rgb) {
			sol2(i - 1, j, N, rgb);
		}
	}

	if (i + 1 < N) {
		if (RGB2[i + 1][j] == rgb) {
			sol2(i + 1, j, N, rgb);
		}
	}

	if (j - 1 >= 0) {
		if (RGB2[i][j - 1] == rgb) {
			sol2(i, j - 1, N, rgb);
		}
	}

	if (j + 1 < N) {
		if (RGB2[i][j + 1] == rgb) {
			sol2(i, j + 1, N, rgb);
		}
	}
}

int main() {
	int N, ans1 = 0, ans2 = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &RGB1[i][j]);

			if (RGB1[i][j] == 'R') {
				RGB2[i][j] = 'G';
			}
			else {
				RGB2[i][j] = RGB1[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (RGB1[i][j] != 0) {
				sol1(i, j, N, RGB1[i][j]);
				ans1++;
			}

			if (RGB2[i][j] != 0) {
				sol2(i, j, N, RGB2[i][j]);
				ans2++;
			}
		}
	}

	printf("%d %d", ans1, ans2);
}