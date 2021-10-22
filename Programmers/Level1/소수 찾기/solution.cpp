#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> isPrime(n+1,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i<=n;i++){
        if(isPrime[i]==true){
            for(int j=2*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(isPrime[i])
            answer++;
    }
    
    
    return answer;
}