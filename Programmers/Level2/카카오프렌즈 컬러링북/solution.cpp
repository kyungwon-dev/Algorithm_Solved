#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    
    
    vector<vector<bool>> map(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]!=0)
                map[i][j] = true;
        }
    }
   
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]){
                number_of_area++;
                queue<pair<int,int>> bfs;
                bfs.push({i, j});
                map[i][j] = false;
                int tmp_size = 0;
                while(!bfs.empty()){
                    int y = bfs.front().first;
                    int x = bfs.front().second;
                    bfs.pop();
                    
                    tmp_size++;
                    for(int i=0;i<4;i++){
                        if(y+dy[i] >= 0 && y+dy[i] <m && x+dx[i] >= 0 && x+dx[i] < n )
                        {
                            if(picture[y][x] == picture[y+dy[i]][x+dx[i]] && map[y+dy[i]][x+dx[i]]){
                               	bfs.push({y+dy[i], x+dx[i]});
                                map[y+dy[i]][x+dx[i]] = false;
                                
                            }
                        }
                        
                    }
                }
                
                max_size_of_one_area = max_size_of_one_area < tmp_size? tmp_size : max_size_of_one_area;
            }
        }
    }   
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;

}