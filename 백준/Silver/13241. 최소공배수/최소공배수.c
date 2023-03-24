#include <stdio.h>

long long int gcd(long long int num1, long long int num2){
    return num1 ? gcd(num2%num1, num1) : num2;
}

int main() {
    long long int num1, num2;
    scanf("%lld %lld", &num1, &num2);
    long long int gcd1 = (num1<num2) ? gcd(num1, num2) : gcd(num2, num1);
    printf("%lld", (long long int)num1*num2/gcd1);
}