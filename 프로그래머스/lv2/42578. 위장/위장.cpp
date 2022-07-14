#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> clothMap;
    int answer = 1;
    for(int i=0;i<clothes.size();i++)
    {
        clothMap[clothes[i][1]];
        clothMap[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    for(auto it=clothMap.begin();it!=clothMap.end();it++)
        answer *= (it->second.size()+1); //(의상종류 별 의상 수 + 1) 
    
    return answer-1; // 아무 의상도 입지 않은 경우
}