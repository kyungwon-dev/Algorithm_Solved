#include <string>
#include <vector>

#define MAX 5001
#define MOD 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;
    long long d[MAX] = {0};
    //init
    d[0] = 1;
    d[2] = 3;
    for(int i=4;i<=n;i++){
        //홀수는 0
        if(i%2 == 1)
            continue;
        // 직전 짝수 개수 * 3 by 2 곱
        d[i] = d[i-2] * d[2];
        // 각 조각 당 특수한 모형의 조각은 2개
        // 각 조각 당 특수 조각 * 2
        for(int j=i-4;j>=0;j-=2){
            d[i] += d[j] * 2;
        }
        d[i] %= MOD;
    }
    
    return (int)d[n];
}