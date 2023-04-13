#include <stdio.h>

char stack[100000] = { 0 };

int index = 0;

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &stack[index]);
        if (stack[index] == 0) {
            index --;
        }
        else {
            index++;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < index; i++) {
        sum += stack[i];
    }
    printf("%d", sum);
}