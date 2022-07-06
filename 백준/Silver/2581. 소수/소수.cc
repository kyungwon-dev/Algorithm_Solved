#include <iostream>
using namespace std;
void calc_prime(int &N, int &M, int &rs, int &mn){
    while(N<=M){
        bool isPrime = true;
        if(N<2){
            N++;
            continue;
        }
            
        for(int i=2;i*i<=N;i++){
            if(N%i==0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            if(rs == -1)
                mn = N;
            rs += N;
        }
        N++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, rs=-1, mn=0;
    cin >> N >> M;
    calc_prime(N, M, rs, mn);
    if(rs == -1)
        cout << rs << "\n";
    else{
        cout << rs+1 << "\n";
        cout << mn << "\n";
    }
            
    return 0;
}