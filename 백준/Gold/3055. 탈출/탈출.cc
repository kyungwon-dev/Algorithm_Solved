#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int diry[] = {1,-1,0,0};
    int dirx[] = {0,0,-1,1};
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char> (m,0));

    vector<vector<int>> wmap(n, vector<int> (m,0));
    vector<vector<int>> bmap(n, vector<int> (m,0));    
    queue<pair<int,int>> q;
    pair<int,int> beaver;
    pair<int,int> cave;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c = cin.get();
            if(c == '\n')
                c = cin.get();
            map[i][j] = c;
            if(c == '*'){
                q.push({i,j});
                wmap[i][j] = 1;
            }
            else{
                if(c == 'D'){
                    cave.first = i;
                    cave.second = j;
                    wmap[i][j] = -1;
                }
                else if(c == 'S'){
                    beaver.first = i;
                    beaver.second = j;
                }
                else if(c == 'X')
                    wmap[i][j] = -1;
            }
        }
    }
    // 물 채우기
    while(!q.empty()){
        int dy = q.front().first;
        int dx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int yy = dy + diry[i];
            int xx = dx + dirx[i];
            if(yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;
            if(wmap[yy][xx] != 0)
                continue;
            wmap[yy][xx] = wmap[dy][dx] + 1;
            q.push({yy,xx});
        }
    }

    q.push({beaver.first,beaver.second});
    bmap[beaver.first][beaver.second] = 1;
    while(!q.empty()){
        int dy = q.front().first;
        int dx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int yy= dy + diry[i];
            int xx = dx + dirx[i];
            if(yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;
            if(bmap[yy][xx] != 0)
                continue;
            if(yy == cave.first && xx == cave.second){
                cout << bmap[dy][dx] << "\n";
                return 0;
            }
            if(wmap[yy][xx] == -1)
                continue;
            if(bmap[dy][dx]+1 >= wmap[yy][xx] && wmap[yy][xx] != 0)
                continue;
            q.push({yy,xx});
            bmap[yy][xx] = bmap[dy][dx]+1;

        }
    }
//     for(auto &w : wmap){
//         for(auto&m : w)
//             cout << m << " ";
//         cout << "\n";
//     }
//     cout << "=====\n";
// for(auto &w : bmap){
//         for(auto&m : w)
//             cout << m << " ";
//         cout << "\n";
//     }
    cout << "KAKTUS\n";
    return 0;
}
