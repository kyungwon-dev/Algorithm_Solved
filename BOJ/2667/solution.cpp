#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> houses;
    int ans = -1;
    int N;
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    cin >> N;
    vector<vector<int> > map(N, vector<int> (N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c = cin.get();
            if(c == '\n')
                c = cin.get();
            map[i][j] = c - '0';
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] > 0 ){
                int tot = 0;
                queue<pair<int, int> > q;
                q.push(make_pair(i,j));
                map[i][j] = ans;
                while(!q.empty()){
                    int sy = q.front().first;
                    int sx = q.front().second;
                    q.pop();
                    tot++;
                    for(int i=0;i<4;i++){
                        int yy = sy + dy[i];
                        int xx = sx + dx[i];
                        if(yy < 0 || yy >= N || xx < 0 || xx >= N)
                            continue;
                        if(map[yy][xx] > 0){
                            q.push(make_pair(yy,xx));
                            map[yy][xx] = ans;

                        }
                    }
                }
                houses.push_back(tot);
                ans--;               
            }
        }
    }
    sort(houses.begin(),houses.end());
    cout << -(ans+1) << "\n";
    for(auto house : houses)
        cout << house << "\n";
    return 0;
}