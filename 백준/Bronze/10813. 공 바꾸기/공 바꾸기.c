#include <stdio.h>

int main(){
    int arr[100] = { 0 };
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++){
        arr[i] = i+1;
    }
    
    for(int i=0; i<M; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        
        int tmp = arr[l-1];
        arr[l-1] = arr[r-1];
        arr[r-1] = tmp;
    }
    
    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    
}