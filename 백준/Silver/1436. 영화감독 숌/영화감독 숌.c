#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    
    int count = 0, disnum = 665;
    while(count != N){
        disnum++;
        int tmp = disnum;
        while(tmp >= 666){
            if(tmp%1000 == 666 ){
                count++;
                break;
            }
            else{
                tmp /= 10;
            }
        }
    }
    printf("%d", disnum);
}