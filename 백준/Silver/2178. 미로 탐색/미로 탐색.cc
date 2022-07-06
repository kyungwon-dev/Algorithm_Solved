#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int diry[4] = {0,0,1,-1};
    int dirx[4] = {1,-1,0,0};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int> (m,0));
    vector<vector<bool>> check(n, vector<bool> (m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c = cin.get();
            if(c == '\n')
                c = cin.get();
            map[i][j] = c-'0';
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    check[0][0] = true;
    while(!q.empty()){
        int dy = q.front().first;
        int dx = q.front().second;
        q.pop();
        for(int j=0;j<4;j++){
            int sy = dy + diry[j];
            int sx = dx + dirx[j];
            if(sy < 0 || sy >= n || sx < 0 || sx >= m)
                continue;
            if(check[sy][sx] || map[sy][sx] == 0)
                continue;
            q.push({sy,sx});
            check[sy][sx] = true;
            map[sy][sx] = map[dy][dx] + 1;

        }
    }
    cout << map[n-1][m-1] << "\n";


    return 0;
}
