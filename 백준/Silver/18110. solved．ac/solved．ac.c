#include <stdio.h>
#include <math.h>

int main() {
	double n, cut = 0, avg = 0;
	int num[30] = { 0 };

	scanf("%lf", &n);

    if (n == 0) {
		printf("0");
		return 0;
	}
    
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		num[tmp - 1]++;
	}


	cut = n * 0.15;
	cut = round(cut);
	n -= cut * 2;

	int lowercut = cut, uppercut = cut;

	for (int i = 0; i < 30 && lowercut > 0; i++) {
		while(num[i] > 0 && lowercut > 0) {
			num[i]--;
			lowercut--;
		}
	}

	for (int i = 29; i > -1 && uppercut > 0; i--) {
		while (num[i] > 0 && uppercut > 0) {
			num[i]--;
			uppercut--;
		}
	}

	for (int i = 0; i < 30; i++) {
		avg += (i + 1) * num[i];
	}

	avg /= n;

	printf("%.0lf", round(avg));
}