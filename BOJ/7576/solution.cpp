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

int main(){
    init();
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    int N, M, tomato = 0, days =0;
    cin >> M >> N;
    vector<vector<int> > map(N, vector<int> (M,0));    
    tomato = N*M;
    queue<pair<int,int> > fill;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
                tomato--;
            }
            if(map[i][j] == 1){
                fill.push(make_pair(i,j));
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
            int sy = fill.front().first;
            int sx = fill.front().second;
            fill.pop();
            for(int i=0;i<4;i++){
                int yy = sy + dy[i];
                int xx = sx + dx[i];
                if(yy < 0 || yy >= N || xx < 0 || xx >= M){
                    continue;
                }
                if(map[yy][xx] == 0){
                    map[yy][xx] = 1;
                    fill.push(make_pair(yy,xx));
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