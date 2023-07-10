#include <stdio.h>

int cnt = 0;

void sol(int A, int B) {
    cnt++;

    if (A == B) {
        printf("%d", cnt);
        return;
    }

    if (A > B) {
        printf("-1");
    }
    else if (B % 2 == 0) {
        sol(A, B / 2);
    }
    else if (B % 10 == 1) {
        sol(A, B / 10);
    }
    else {
        printf("-1");
    }
}

int main() {
    int A, B;
    

    scanf("%d %d", &A, &B);

    sol(A, B);
}