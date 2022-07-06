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
    int n;
    cin >> n;
    vector<long long> wine(n+1);
    for(int i=1;i<=n;i++)
        cin >> wine[i];
    vector<vector<long long>> d(3, vector<long long> (n+1,0));
    d[0][1] = 0;d[1][1] = wine[1]; d[2][1] = 0;
    for(int i=2;i<=n;i++){
        d[0][i] = max(d[0][i-1], max(d[1][i-1], d[2][i-1]));
        d[1][i] = d[0][i-1] + wine[i];
        d[2][i] = d[1][i-1] + wine[i];
    }
    cout << max(d[0][n], max(d[1][n], d[2][n])) << "\n";


    return 0;
}
