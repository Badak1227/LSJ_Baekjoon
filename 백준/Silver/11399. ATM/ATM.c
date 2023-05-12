#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    int arr[1000] = { 0 };
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    qsort(arr, n, sizeof(int), compare);

    int sum = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		answer += sum;
	}

    printf("%d\n", answer);
    return 0;
}