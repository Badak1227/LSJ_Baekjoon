#include <stdio.h>

int main() {
    
    double count = 0;
    double total = 0;

    for (int i = 0; i < 20; i++) {
        double credit;
        char grade[3] = { 0 };
        scanf("%*s %lf %s", &credit, grade);
        switch (grade[0]) {
            case 'A':
                count += credit;

                if (grade[1] == '+') {
                    total += credit * 4.5;
                }
                else {
                    total += credit * 4;
                }
                break;
            case 'B':
                count += credit;

                if (grade[1] == '+') {
                    total += credit * 3.5;
                }
                else {
                    total += credit * 3;
                }
                break;
            case 'C':
                count += credit;

                if (grade[1] == '+') {
                    total += credit * 2.5;
                }
                else {
                    total += credit * 2;
                }
                break;
            case 'D':
                count += credit;

                if (grade[1] == '+') {
                    total += credit * 1.5;
                }
                else {
                    total += credit * 1;
                }
                break;
            case 'F':
                count += credit;

                break;
        }
    }
    printf("%lf", total / count);
}