#include <stdio.h>

int prefixSum[1000005];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // 입력 배열의 누적 합을 구합니다.
    prefixSum[0] = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);
        prefixSum[i] = (prefixSum[i - 1] + num) % M;
    }
    
    // 누적 합의 나머지가 같은 값의 개수를 세기 위해 배열을 초기화합니다.
    long long cnt[1005] = {0};
    for (int i = 0; i <= N; i++) {
        cnt[prefixSum[i]]++;
    }
    
    long long answer = 0;
    for (int i = 0; i < M; i++) {
        // 나머지가 같은 값의 개수 중 2개 이상 선택하는 경우의 수를 계산합니다.
        answer += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    
    printf("%lld\n", answer);
    
    return 0;
}