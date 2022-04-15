#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int mx = 0;
    int dy[3] = {0,-1,-1};
    int dx[3] = {-1,-1,0};
    if(board.size()==1 || board[0].size()==1){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 1)
                    return 1;
            }
        }
        return answer;
    }
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[i].size();j++){
            if(board[i][j] == 1){
                int tmp = INT32_MAX;
                for(int k=0;k<3;k++){
                    int sy = dy[k] + i;
                    int sx = dx[k] + j;
                    if(sy >= board.size() || sy < 0 || sx >= board[0].size() || sx < 0)
                        continue;
                    tmp = min(tmp,board[sy][sx]);
                }
                board[i][j] = max(tmp+1, board[i][j]);
                answer = max(answer, board[i][j]);
            }
        }
    }
    
    
    return answer * answer;
}