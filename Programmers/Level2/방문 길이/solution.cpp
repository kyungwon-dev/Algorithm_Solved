#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first)
        return a.first > b.first;
    return a.second > b.second;
}

int solution(string dirs) {
    int dy[4] = {0,0,1,-1};
    int dx[4] = {-1,1,0,0};
    string cvrt = "";
    for(auto dir : dirs){
        if(dir == 'U')
            cvrt.push_back('3');
        else if(dir == 'D')
            cvrt.push_back('2');
        else if(dir == 'R')
            cvrt.push_back('1');
        else
            cvrt.push_back('0');
    }
    set<pair<pair<int, int>, pair<int, int> > > pathes;
    int sy = 5, sx = 5;
    for(int i=0;i<cvrt.length();i++){
        int yy = sy + dy[cvrt[i] - '0'];
        int xx = sx + dx[cvrt[i] - '0'];
        
        if(yy >= 0 && yy < 11 && xx>=0 && xx < 11){
            vector<pair<int,int> > ps;
            ps.push_back(make_pair(yy,xx));
            ps.push_back(make_pair(sy,sx));
            sort(ps.begin(),ps.end(),cmp);
            pathes.insert(make_pair(ps[0],ps[1]));
            sy = yy; sx = xx;
        }   
    }
    return pathes.size();
}