#include <string>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int calc(vector<int> idx){
    if(idx[0] == -1){
        int subsum = accumulate(idx.begin(),idx.end(),0);
        if(subsum == ( (-1) * (idx.size())))
            return 1;
        return 0;
    }
    for(int i=1;i<idx.size();i++){
        if(idx[i] == -1){
            int subsum = accumulate(idx.begin()+i,idx.end(),0);
            if(subsum == ( (-1) * (idx.size()-i)))
                return 1;
            return 0;
        }
        else{
            if(idx[i-1] > idx[i])
                return 0;
        }
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;    
    for(int i=0;i<skill_trees.size();i++){
        vector<int> idx(skill.length(),-1);
        for(int j=0;j<skill.length();j++){
            if(skill_trees[i].find(skill[j]) == string::npos)
                continue;
            idx[j] = skill_trees[i].find(skill[j]);
        }
        answer += calc(idx);
    }
    
    
    
    return answer;
}