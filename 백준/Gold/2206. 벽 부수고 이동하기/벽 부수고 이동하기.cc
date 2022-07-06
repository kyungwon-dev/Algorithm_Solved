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
    int y, x;
    cin >> y >> x;
    vector<vector<int>> map(y ,vector<int> (x));
    vector<vector<vector<int>>> check(y, vector<vector<int>> (x, vector<int> (2)));
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            char c= cin.get();
            if(c=='\n')
                c = cin.get();
            map[i][j] = c - '0';
        }
    }
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    check[0][0][0] = 1;
    while(!q.empty()){
        int dy , dx, b;
        tie(dy,dx,b) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int sy = dy + diry[i];
            int sx = dx + dirx[i];
            if(sy < 0 || sy >= y || sx < 0 || sx >= x)
                continue;
            if(check[sy][sx][b] !=0)
                continue;
            if(map[sy][sx] == 0){
                q.push(make_tuple(sy,sx,b));
                check[sy][sx][b] = check[dy][dx][b]+1;
            }
            else{
                if(b==0){
                    q.push(make_tuple(sy,sx,b+1));
                    check[sy][sx][b+1] = check[dy][dx][b] + 1;

                }
            }
        }
    }
    if(check[y-1][x-1][0] != 0 && check[y-1][x-1][1] != 0)
        cout << min(check[y-1][x-1][0],check[y-1][x-1][1])  << "\n";
    else if(check[y-1][x-1][0] != 0)
        cout << check[y-1][x-1][0] << "\n";
    else if(check[y-1][x-1][1] != 0)
        cout << check[y-1][x-1][1] << "\n";
    else
        cout << "-1\n";

    return 0;
}
