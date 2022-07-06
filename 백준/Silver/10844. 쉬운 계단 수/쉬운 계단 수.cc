#include <iostream>
#include <vector>
#include <numeric>
#define MAX 101
#define MOD 1000000000

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    long long D[101][10] = {0,};
    for(int i=1;i<10;i++)
        D[1][i] =1;
    for(int i=2;i<101;i++){
        for(int j=0;j<10;j++){
            if(j==0)
                D[i][j] = D[i-1][j+1];
            else if(j==9)
                D[i][j] = D[i-1][j-1];
            else
                D[i][j] = D[i-1][j-1] + D[i-1][j+1];
            D[i][j] = D[i][j] % MOD;
        }
    }
    long  long ans = 0;
    for(auto d : D[n])
        ans = ans + ( d % MOD);
    cout << ans % MOD<< "\n";
    return 0;
}
