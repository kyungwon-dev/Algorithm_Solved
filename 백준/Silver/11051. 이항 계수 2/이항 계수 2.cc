#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int n,m;
    cin >> n >> m;
    vector<vector<long long> > num(1001, vector<long long> (1001,1));
    for(int i=2;i<1001;i++){
        for(int j=1;j<i;j++){
            num[i][j] = (num[i-1][j-1] + num[i-1][j] ) % 10007;
        }
    }
    cout << num[n][m] << "\n";    


    return 0;
}