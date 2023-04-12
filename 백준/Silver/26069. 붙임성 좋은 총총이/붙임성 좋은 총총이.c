#include <stdio.h>
#include <string.h>

char infected[1000][21] = { 0 };

int idx = 1;

int count = 1;
    
int search(char str[]) {
	for (int i = 0; i < idx; i++) {
		if (strcmp(str, infected[i]) == 0) {
			return 1;
		}
	}
	return 0;
}

int main(){
	strcpy(infected[0], "ChongChong");
    
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		char str1[21] = "", str2[21] = "";
		scanf("%s %s", str1, str2);
		int result1 = search(str1);
		int result2 = search(str2);
		if (result1 != result2) {
			if (!result1) {
				strcpy(infected[idx++], str1);
			}
			else {
				strcpy(infected[idx++], str2);
			}
			count++;
		}
	}
	
	printf("%d", count);

	return 0;
}