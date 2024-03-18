#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i=0;i<targets.size();i++){
        int calc = 0;
        for(int j=0;j<targets[i].size();j++){
            int cnt = INT32_MAX;
            for(auto k : keymap){
                if(k.find(targets[i][j]) == -1) continue;
                cnt = min(cnt, (int) k.find(targets[i][j]));
                
            }
            if(cnt != INT32_MAX)
                calc += cnt + 1;
            else{
                calc = 0;
                break;
            }
        }
        if(calc != 0)
            answer.push_back(calc);
        else{
            answer.push_back(-1);
        }
            
    }
    return answer;
}