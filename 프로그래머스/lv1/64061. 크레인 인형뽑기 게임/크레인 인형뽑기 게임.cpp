#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> rs;
    int answer = 0;
    for(int i=0;i<moves.size();i++)
    {
        
        for(int j=0;j<board.size();j++)
        {
            if(board[j][moves[i]-1] != 0)
            {
                rs.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    //for(int i=0;i<rs.size();i++)
    //{cout << rs[i] << " ";
    //}
    //cout << "\n";
    for(int i=1;i<rs.size();i++)
    {
        if(rs[i-1] == rs[i])
        {//cout << rs[i] << " " << i << " " << i - 1 <<  "\n";
            rs.erase(rs.begin()+i-1);
            rs.erase(rs.begin()+i-1);
            i-=2;
            answer+=2;
        }
    }
        
    //cout <<  "\n";
    
    return answer;
}