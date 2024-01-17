#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    
    if(arr.size() == arr[0].size()) return arr;
    int row = arr.size();
    int col = arr[0].size();
    if(row > col) col = row;
    else row = col;
    vector<vector<int>> answer(row, vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i >= arr.size())
                answer[i][j] = 0;
            else if(j >= arr[i].size())
                answer[i][j] = 0;
            else
                answer[i][j] = arr[i][j];
        }
    }
    return answer;
}