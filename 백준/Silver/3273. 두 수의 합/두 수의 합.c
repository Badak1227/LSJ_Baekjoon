#include <stdio.h>
#include <stdlib.h>

int compare(int* num1, int* num2) {
	return *num1 - *num2;
}

int main() {
	int num[100001] = { 0 };
	
	int n, x, cnt = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	scanf("%d", &x);

    qsort(num, n, sizeof(int), compare);
    
	int i = 0, j = n-1;
	while (i < j) {
        if(num[i] + num[j] < x){
            i++;
        }
        else if(num[i] + num[j] > x){
            j--;
        }
        else{
            cnt++;
            j--;
        }
	}
    
	printf("%d", cnt);
}