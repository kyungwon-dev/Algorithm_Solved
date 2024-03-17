#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    
    int dy[4] = {0,1,0,-1}; 
    int dx[4] = {1,0,-1,0};
    
    int num = 1;
    int sy = 0, sx = 0;
    int dir = 0; // 
    while(num <= (n*n)){
        if(answer[sy][sx] == 0){
            answer[sy][sx] = num;
        }
        if(num == (n*n)) break;
        if(sy + dy[dir] >= n || sy + dy[dir]< 0 || sx + dx[dir] >= n || sx + dx[dir]< 0){
            dir = (dir + 1) % 4;
            continue;
        }
        if(answer[sy + dy[dir]][sx + dx[dir]] != 0){
            dir = (dir + 1) % 4;
            continue;
        }
            
        sy = sy + dy[dir];
        sx = sx + dx[dir];
        num++;
    }
    return answer;
}