#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    if(N==M && M==K)
        cout << 10000 + (K*1000) << "\n";
    else if(N!=M && N!=K && K!=M){
        cout << max(N,max(K,M)) * 100 << "\n";
    }
    else{
        if(N==M)
            cout << 1000 + (100 * N) << "\n";
        else
            cout << 1000 + (100 * K) << "\n";
    }
    
    
    return 0;
}