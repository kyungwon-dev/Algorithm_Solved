#include <iostream>

using namespace std;
bool isPrime(int N){
    for(long long i=2;i*i<=N;i++){
        if(N%i==0)
            return false;
    }
    return true;
}

int main(){
    bool prime[1000001];
    prime[1] = true;
    for(int i=2;i<1000001; i++){
        if(prime[i] == false){
            if(isPrime(i)){
                for(int j=(2*i);j<1000001;j+=i){
                    if(prime[j] == false)
                        prime[j] = true;
                }
            }
        }
    }
    int N,M;
    cin >> N >> M;
    for(int i=N; i<=M; i++){
        if(prime[i] == false)
            cout << i << "\n";
    }
    
    return 0;
}