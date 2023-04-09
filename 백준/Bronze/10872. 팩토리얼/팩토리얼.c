#include <stdio.h>

int fac(int num) {
    int tmp = 1;
    for (int i = num; i >= 2; i--) {
        tmp *= i;
    }
    return tmp;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fac(n));
}