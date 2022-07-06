#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, M;
        cin >> N >> M;
        int rs = gcd(N ,M);
        cout << N * M / rs << "\n";
    }
    
    return 0;
}