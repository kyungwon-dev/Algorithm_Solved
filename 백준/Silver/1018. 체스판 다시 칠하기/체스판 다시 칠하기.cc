#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > map(n, vector<bool> (m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c == 'W')
                map[i][j] = true;
        }
    }
    int cnt = 0;

    int mn = INT32_MAX;
    for(int i=0;i<=(n-8);i++){
        for(int j=0;j<= (m-8);j++){
            vector<vector<bool> > submap(8, vector<bool>(8, false));
            for(int tp=0;tp<2;tp++){
                cnt = 0;
                submap[0][0] = tp==0? true : false;
                if(submap[0][0] != map[i][j])
                    cnt++;
                for(int k=1;k<8;k++){
                    submap[k][0] = !submap[k-1][0];
                    if(submap[k][0] != map[i+k][j])
                        cnt++;
                }
                for(int k=0;k<8;k++){
                    for(int l=1;l<8;l++){
                        submap[k][l] = !submap[k][l-1];
                        if(submap[k][l] != map[i+k][j+l])
                            cnt++;
                    }
                }
                mn = min(cnt, mn);
            }
        }
    }
    cout << mn << "\n";
    
    
    return 0;
}