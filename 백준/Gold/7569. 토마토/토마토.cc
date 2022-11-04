#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void printmap(vector<vector<int> > &map){
    cout << "==========\n";
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

struct Dir{
    int x,y,z;
    Dir(int a,int b,int c){
        z = a;
        y = b;
        x = c;
    }
};


int main(){
    init();
    int dy[6] = {0,0,1,-1,0,0};
    int dx[6] = {1,-1,0,0,0,0};
    int dz[6] = {0,0,0,0,1,-1};

    int N, M, K, tomato = 0, days =0;
    cin >> N >> M >> K; // x, y, z
    vector<vector<vector<int>> > map(K, vector<vector<int>> (M, vector<int> (N,0)));    

    tomato = N*M*K;
    queue<Dir> fill;
    for(int i=0;i<K;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                cin >> map[i][j][k];
                if(map[i][j][k] !=0){
                    tomato--;
                }                
                if(map[i][j][k] == 1){
                    fill.push(Dir(i,j,k));
                }
            }
        }
    }
    if(tomato==0){
        cout << days << "\n";
        return 0;
    }
    while(!fill.empty()){
        if(tomato!=0)
            days++;
        int loop = fill.size();
        for(int i=0;i<loop;i++){
            int sz = fill.front().z;
            int sy = fill.front().y;
            int sx = fill.front().x;

            fill.pop();
            for(int i=0;i<6;i++){
                int yy = sy + dy[i];
                int xx = sx + dx[i];
                int zz = sz + dz[i];
                if(yy < 0 || yy >= M || xx < 0 || xx >= N || zz < 0 || zz >= K){
                    continue;
                }
                if(map[zz][yy][xx] == 0){
                    map[zz][yy][xx] = 1;
                    fill.push(Dir(zz,yy,xx));
                    tomato--;
                }
            }
        }
    }
    if(tomato!=0)
        cout << "-1\n";
    else
        cout << days<< "\n";

    return 0;
}