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
    int diry[] = {1,-1,0,0};
    int dirx[] = {0,0,-1,1};
    int y, x;
    cin >> x >> y;
    vector<vector<int>> map(y ,vector<int> (x));
    vector<vector<int>> check(y, vector<int> (x,-1));
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            char c= cin.get();
            if(c=='\n')
                c = cin.get();
            map[i][j] = c - '0';
        }
    }
    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    check[0][0] = 0;
    while(!dq.empty()){
        int yy = dq.front().first;
        int xx = dq.front().second;
        dq.pop_front();
        for(int i=0;i<4;i++){
            int sy = yy + diry[i];
            int sx = xx + dirx[i];
            if(sy < 0 || sy >= y || sx < 0 || sx >= x)
                continue;
            if(check[sy][sx] == -1){
                if(map[sy][sx] == 0){
                    dq.push_front({sy,sx});
                    check[sy][sx] = check[yy][xx];
                }
                else{
                    dq.push_back({sy,sx});
                    check[sy][sx] = check[yy][xx] + 1;
                }

            }
        }

    }
    cout << check[y-1][x-1] << "\n";
    return 0;
}
