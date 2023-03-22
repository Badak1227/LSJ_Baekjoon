#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int x = x = (c * e - b * f) / (a * e - b * d);;
    int y;
    if (b == 0) {
        y = (f - d * x) / e;
        
    }
    else {
        y = (c - a * x) / b;
    }

    printf("%d %d", x, y);
}