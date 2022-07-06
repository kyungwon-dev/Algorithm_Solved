#include <iostream>
using namespace std;

bool isPrime(int n){
    for(long long i=2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    if(N==1)
        return 0;
    else{
        for(int i=2;i*i<=N;i++){
            while(N%i == 0){
                cout << i << "\n";
                N = N / i;
            }
        }
        if(N!=1) cout << N << "\n";
    }
    return 0;
}