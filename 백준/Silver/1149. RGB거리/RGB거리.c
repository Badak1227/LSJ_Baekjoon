#include <stdio.h>

int main() {
	int N;

	int rgb[2][3];

	scanf("%d", &N);

	scanf("%d %d %d", &rgb[0][0], &rgb[0][1], &rgb[0][2]);

	for (int i = 1; i < N; i++) {
		scanf("%d %d %d", &rgb[1][0], &rgb[1][1], &rgb[1][2]);

		int tmp1 = (rgb[0][1] < rgb[0][2] ? rgb[0][1] : rgb[0][2]) + rgb[1][0];
		int tmp2 = (rgb[0][0] < rgb[0][2] ? rgb[0][0] : rgb[0][2]) + rgb[1][1];
		int tmp3 = (rgb[0][0] < rgb[0][1] ? rgb[0][0] : rgb[0][1]) + rgb[1][2];
		rgb[0][0] = tmp1;
		rgb[0][1] = tmp2;
		rgb[0][2] = tmp3;
	}
	
	int min = 1000000;
	for (int i = 0; i < 3; i++) {
		min = rgb[0][i] < min ? rgb[0][i] : min;
	}

	printf("%d", min);

	return 0;
}