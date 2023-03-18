#include <stdio.h>

int main(){
    int N, x[50] = {0}, y[50] = {0}, rank[50] = {0};
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=0; i<N; i++){
        rank[i] = 1;
    }
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(x[i]>x[j] && y[i]>y[j]){
                rank[j]++;
            }
            else if(x[i]<x[j] && y[i]<y[j]){
                rank[i]++;
            }
        }
    }
    for(int i=0; i<N; i++){
        printf("%d ", rank[i]);
    }
}