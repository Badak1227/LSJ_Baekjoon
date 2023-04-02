#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, num, count =0;
    scanf("%d", &N);
    int* nums = (int*)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
    scanf("%d", &num);
    for(int i=0; i<N; i++){
        if(nums[i] == num){
            count++;
        }
    }
    printf("%d", count);
}