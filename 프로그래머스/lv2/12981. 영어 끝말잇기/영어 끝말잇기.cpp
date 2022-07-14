#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    answer.push_back(1);answer.push_back(0);
    s.insert(words[0]);
    for(int i=1;i<words.size();i++){
        int size = s.size();
        s.insert(words[i]);
        answer[0] = answer[0] % n + 1;
        if(words[i-1][words[i-1].size()-1] != words[i][0] || size == s.size()){
            answer[1] = i/n+1;
            break;
        }
    }
    if(answer[1] == 0)
        answer[0] = 0;
    return answer;
}