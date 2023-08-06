#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int c;
        scanf("%d", &c);

        int quarters = c / 25;
        c %= 25;
        int dimes = c / 10;
        c %= 10;
        int nickels = c / 5;
        c %= 5;
        int pennies = c;

        printf("%d %d %d %d\n", quarters, dimes, nickels, pennies);
    }

    return 0;
}
