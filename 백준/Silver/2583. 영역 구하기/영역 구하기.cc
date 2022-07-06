#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}

int main(){
    init();
    int n, m, k;
    cin >> n >> m >> k;
    int dirY[4] = {1,-1,0,0};
    int dirX[4] = {0,0,1,-1};
    //n++;m++;
    vector<vector<int> > map(n, vector<int> (m, 0));
    for(int i=0;i<k;i++){
        int sy,sx,dy,dx;
        cin >> sx >> sy >> dx >> dy;
        for(int y=sy;y<dy;y++){
            for(int x = sx;x<dx;x++)
                map[y][x] = 1;
        }
    }
    queue<pair<int, int> > bfs;
    vector<int> answers;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0){
                ans = 0;
                bfs.push({i, j});
                map[i][j] = 2;
                while(!bfs.empty()){
                    int sy = bfs.front().first;
                    int sx = bfs.front().second;
                    bfs.pop();
                    ans++;
                    for(int idx = 0; idx<4;idx++){
                        int dy = sy + dirY[idx];
                        int dx = sx + dirX[idx];
                        if(dy <n && dy>=0 && dx < m && dx >= 0){
                            if(map[dy][dx] == 0){
                                map[dy][dx] = 2;
                                bfs.push({dy,dx});
                            }
                            
                        }
                    }
                }
               answers.push_back(ans);
            }
        }
    }
    sort(answers.begin(),answers.end());
    cout << answers.size() << "\n";
    for(auto a : answers)
        cout << a << " ";
    cout << "\n";
    return 0;
}