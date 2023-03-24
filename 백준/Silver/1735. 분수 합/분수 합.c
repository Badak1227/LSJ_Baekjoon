#include <stdio.h>

int gcd(int num1, int num2){
    if(num1 > num2){
        return num2 ? gcd(num1%num2, num2) : num1;
    }
    else{
        return num1 ? gcd(num2%num1, num1) : num2;
    }
}

int main(){
    int up1, down1, up2, down2;
    scanf("%d %d %d %d", &up1, &down1, &up2, &down2);
    int gcd1 = gcd(down1, down2);
    int lnm1 = down1*down2/gcd1;
    up1 *= lnm1/down1;
    up2 *= lnm1/down2;
    
    int up = up1 + up2;
    int down = lnm1;
    int gcd2 = gcd(up, down);
    printf("%d %d", up/gcd2, down/gcd2);
}