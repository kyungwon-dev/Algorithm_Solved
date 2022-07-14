#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Coordinate{
    int y,x;
    Coordinate(int a, int b){ y=a;x=b;}
};

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    int diry[3] = {0,-1,-1};
    int dirx[3] = {1,1,0};
    
    while(true){
        vector<pair<int,int>> score;
        // 조건에 맞는 블록 찾기
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '0')
                    continue;
                bool isErase = true;
                for(int k=0;k<3;k++){
                    int dy = i + diry[k];
                    int dx = j + dirx[k];
                    if(dy <0 || dy >= m || dx < 0 || dx >= n){
                        isErase = false;
                        break;
                    }
                    if(board[dy][dx] != board[i][j]){
                        isErase = false;
                        break;
                    }
                }
                if(isErase){
                    score.push_back({i,j});
                    for(int k=0;k<3;k++)
                        score.push_back({i + diry[k], j + dirx[k]});
                }
            }
        }
        sort(score.begin(),score.end());
        score.erase(unique(score.begin(),score.end()),score.end());
        answer += score.size();

        if(score.size()==0)
            break;
        // 제거
        for(auto co : score)
            board[co.first][co.second] = '0';
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(board[j][i]=='0'){
                    for(int k=j;k>=0;k--){
                        if(board[k][i] != '0'){
                            swap(board[j][i],board[k][i]);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}