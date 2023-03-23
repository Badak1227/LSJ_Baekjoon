#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    int nums[2];
    for(int i=0; i<T; i++){
        scanf("%d %d", &nums[0], &nums[1]);
        int tmp[2] = {1, 1};
        while(nums[0]*tmp[0] != nums[1]*tmp[1]){
            if(nums[0]*tmp[0] < nums[1]*tmp[1]){
                tmp[0]++;
            }
            else{
                tmp[1]++;
            }
        }
        printf("%d\n", nums[0]*tmp[0]);
    }
}