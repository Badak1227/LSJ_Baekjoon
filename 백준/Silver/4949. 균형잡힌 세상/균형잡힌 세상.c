#include <stdio.h>
#include <string.h>

void test(char PS[]) {

    char stack[101] = { 0 };
    int index = 0;
    int VPS = 1;

    int j = 0;

    while (PS[j]) {

        if (PS[j] == '(' || PS[j] == '[') {
            stack[index++] = PS[j];
        }
        else if (PS[j] == ')') {
            if (index > 0 && stack[index - 1] == '(') {
                index--;
            }
            else {
                VPS = 0;
                break;
            }
        }
        else if (PS[j] == ']') {
            if (index > 0 && stack[index - 1] == '[') {
                index--;
            }
            else {
                VPS = 0;
                break;
            }
        }

        j++;
    }

    VPS = index > 0 ? 0 : VPS;
    printf("%s\n", VPS == 1 ? "yes" : "no");
    return;
}

int main() {

    while(1){
        char PS[101] = { 0 };
        gets(PS);
        if (strcmp(PS,".") == 0) break;
        test(PS);
    }
}