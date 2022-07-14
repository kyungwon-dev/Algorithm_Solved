#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int diry[] = {0,-1,0,1};
int dirx[] = {-1,0,1,0};

int rotate(char c, int pos){
    if(c == 'R')
        return pos == 3 ? 0 : pos + 1;
    else if(c == 'L')
        return pos == 0 ? 3 : pos - 1;
    return pos;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector< vector< vector<bool> > > isVisit(grid.size(), vector<vector<bool>> (grid[0].size(), vector<bool> (4)));
    for(int sy=0;sy<grid.size();sy++){
        for(int sx=0;sx<grid[sy].size();sx++){
            for(int i=0;i<4;i++){
                int cnt=0, pos=i, y=sy, x=sx;
                while(!isVisit[y][x][pos]){    
                    isVisit[y][x][pos] = true; 
                    pos = rotate(grid[y][x], pos);
                    y = y + diry[pos]; x = x + dirx[pos];
                    if(y < 0){
                        y = grid.size()-1;
                    }
                    else if(y >= grid.size()){
                        y = 0;
                    }
                    if(x < 0){
                        x = grid[0].size()-1;
                    }
                    else if(x >= grid[0].size()){
                        x = 0;
                    }
                    cnt++;            

                }
                if(cnt > 0)
                    answer.push_back(cnt);  
            }        
        }
    }
        
    sort(answer.begin(),answer.end());
    
    return answer;
}