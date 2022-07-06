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
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int> (n+1,0));
        vector<vector<int>> d(3, vector<int> (n+1,0));
        for(int j=0;j<2;j++){
            for(int k=1;k<=n;k++)
                cin >> a[j][k];
        }
        for(int j=1;j<=n;j++){
            d[0][j] = max(d[0][j-1], max(d[1][j-1], d[2][j-1]));
            d[1][j] = max(d[0][j-1] + a[0][j], d[2][j-1] + a[0][j]);
            d[2][j] = max(d[0][j-1] + a[1][j], d[1][j-1] + a[1][j]);
        }
        cout << max(d[0][n], max(d[1][n], d[2][n])) << "\n";
    }

    return 0;
}