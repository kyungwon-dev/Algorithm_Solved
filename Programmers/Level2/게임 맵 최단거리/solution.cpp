#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct pos{
    int y,x;
    pos(int a,int b){
        y=a;x=b;
    }
};

bool isMove(int y, int x, int my, int mx){
    if(y<0 || y>=my || x <0 || x >= mx)
        return false;
    return true;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    //direction
    int diry[] = {-1,0,0,1};
    int dirx[] = {0,1,-1,0};
    queue<pos> q;
    q.push(pos(0,0));
    while(!q.empty()){
        pos p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int dy = diry[i] + p.y;
            int dx = dirx[i] + p.x;
            if(!isMove(dy,dx,maps.size(),maps[0].size()))
                continue;
            if(maps[dy][dx] != 1)
                continue;
            maps[dy][dx] = maps[p.y][p.x]+1;
            q.push(pos(dy,dx));
        }
    }
    if(maps[maps.size()-1][maps[0].size()-1]==1)
        return -1;
    return maps[maps.size()-1][maps[0].size()-1];
}