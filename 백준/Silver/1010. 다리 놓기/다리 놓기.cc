#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    vector<vector<long long> > num(31, vector<long long> (31,1));
    for(int i=2;i<31;i++){
        for(int j=1;j<i;j++){
            num[i][j] = (num[i-1][j-1] + num[i-1][j] ) ;
        }
    }
    int n,m, T;
    cin >> T;
    for(int i=0;i<T;i++){  
        cin >> n >> m;
        cout << num[m][n] << "\n";
    }
    
    return 0;
}