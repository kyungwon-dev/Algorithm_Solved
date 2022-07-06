#include <iostream>
#include <vector>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n, k;
    cin >> n >> k;
    vector<vector<long long >> d(n+1, vector<long long> (k+1,0));
    for(int i=1;i<=k;i++)
        d[1][i] = i;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            d[i][j] = d[i-1][j] + d[i][j-1];
            d[i][j] %= 1000000000;
        }
    }
    cout << d[n][k] << "\n";;
    return 0;
}
