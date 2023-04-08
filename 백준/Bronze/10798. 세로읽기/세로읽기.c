#include <stdio.h>

int main(){
    char str[5][16] = {
        {0},
        {0},
        {0},
        {0},
        {0}
    };
    for(int i=0; i<5; i++){
        scanf("%s", str[i]);
    }
    
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(str[j][i]){
                printf("%c", str[j][i]);
            }
        }
    }
}