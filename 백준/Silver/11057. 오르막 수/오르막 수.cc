#include <iostream>
#include <vector>
#include <numeric>
#define MAX 1001
#define MOD 10007

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
    int D[MAX][10] = {0,};
    for(int i=0;i<10;i++)
        D[1][i] =1;
    for(int i=2;i<MAX;i++){
        int sum = 0;
        D[i][0] = 1;
        for(int j=1;j<10;j++){
            D[i][j] = (D[i][j-1] + D[i-1][j]) % MOD;
        }
    }
    int ans = 0;
    for(auto d : D[n])
        ans += d;
    cout << ans % MOD << "\n";
    return 0;
}
