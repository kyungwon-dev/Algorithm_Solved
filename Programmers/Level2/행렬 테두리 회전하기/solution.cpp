#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
int diry[] = {0,1,0,-1};
int dirx[] = {1,0,-1,0};

bool isMove(int y, int x, int mxy, int mxx, int mny, int mnx){
    if(y<0 || y >=map.size() || x <0 || x >=map[0].size())
        return false;
    if(y< mny|| y >mxy || x < mnx || x >mxx)
        return false;
    return true;
}

void init(int rows, int columns){
    map.resize(rows, vector<int> (columns,0));
    int value=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++)
            map[i][j] = value++;
    }
}

int rotate(int sy, int sx, int dy, int dx){
    int trial = (dy-sy)*2 + (dx-sx)*2;
    int yy = sy, xx = sx, dir=0, tmp=map[sy][sx], mn= map[sy][sx];
    while(trial != 0){
        
        if(!isMove(yy + diry[dir],xx+dirx[dir],dy,dx,sy,sx)){
            dir = (dir+1)%4;
        }
        yy += diry[dir]; xx += dirx[dir];
        swap(tmp,map[yy][xx]);
        trial--;
        mn = min(mn,tmp);
    }
    return mn;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    for(auto query : queries){
        answer.push_back(rotate(query[0] - 1, query[1] - 1, query[2] - 1,query[3] - 1));
    }
    return answer;
}