#include <stdio.h>

int fibcount = 1;
int fcount = 0;

int fib(n) {
    

    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        fibcount++;
        return (fib(n - 1) + fib(n - 2));
    }
}

int f[40] = { 0 };

int fibonacci(n) {
    

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < n; i++) {
        fcount++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n - 1];
}

int main() {
    int N;
    scanf("%d", &N);

    fib(N);
    fibonacci(N);

    printf("%d %d", fibcount, fcount);
}