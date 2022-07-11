#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> tmp;
    
    for(int i=0;i<commands.size();i++)
    {
        tmp.clear();
        tmp.assign(array.begin()+commands[i][0]-1,array.begin()+commands[i][1]);
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[commands[i][2]-1]);
    }
    return answer;
}