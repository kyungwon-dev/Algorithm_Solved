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
    while(true){
        int w, h;
        cin >> w >> h;
        if(w==0 && h==0) break;
        vector<vector<int>> map(h,vector<int> (w,0) );
        vector<vector<bool>> check(h, vector<bool> (w,false));
        int diry[8] = {-1,-1,-1,0,0,1,1,1};
        int dirx[8] = {-1,0,1,-1,1,-1,0,1};
        int island = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                cin >> map[i][j];
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j] == 1 && check[i][j] == false){
                    queue<pair<int,int>> q;
                    q.push({i,j});check[i][j] = true;
                    while(!q.empty()){
                        int dy = q.front().first;
                        int dx = q.front().second;
                        q.pop();
                        for(int k=0;k<8;k++){
                            int sy = dy + diry[k];
                            int sx = dx + dirx[k];
                            if(sy < 0 || sy >= h || sx < 0 || sx >= w)
                                continue;
                            if(map[sy][sx] == 0 || check[sy][sx])
                                continue;
                            q.push({sy,sx});
                            check[sy][sx] = true;
                        }
                    }
                    island++;
                }
            }
        }
        cout << island << "\n";
    }


    return 0;
}
