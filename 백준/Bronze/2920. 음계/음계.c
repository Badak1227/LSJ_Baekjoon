#include <stdio.h>

int main() {
	int um[8], setting = 3;

	scanf("%d", &um[0]);

	if (um[0] == 1) {
		setting = 1;

		for (int i = 1; i < 8; i++) {
			scanf("%d", &um[i]);
			
			if (um[i] - um[i - 1] != 1) {
				setting = 3;
				break;
			}
		}
	}
	else if (um[0] == 8) {
		setting = 2;

		for (int i = 1; i < 8; i++) {
			scanf("%d", &um[i]);

			if (um[i] - um[i - 1] != -1) {
				setting = 3;
				break;
			}
		}
	}

	switch (setting) {
		case 1:
			printf("ascending");
			break;
		case 2:
			printf("descending");
			break;
		case 3:
			printf("mixed");
			break;
	}
}