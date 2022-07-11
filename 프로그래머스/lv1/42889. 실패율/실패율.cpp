#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

bool cmp(const pair<int,double> &a, const pair<int,double> &b ){
    if(a.second == b.second)
        return a.first < b.first; 
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> userStatics;
        
    //sort(stages.begin(),stages.end());
    //map<int,int> clear_user;
    for(int i=0;i<=N;i++)
        userStatics.push_back({i+1,0});
    for(int stage : stages)
        userStatics[stage-1].second++;
    int userClear = stages.size();
    
    for(auto &user : userStatics)
    {
        if(user.second==0)
            continue;
        int tmp = userClear - user.second;
        user.second = user.second / userClear;
        userClear = tmp;
        if(userClear==0)
            break;
    }
    
    sort(userStatics.begin(),userStatics.end(),cmp);
    for(auto user : userStatics)
    {
        if(user.first==N+1)
            continue;
        answer.push_back(user.first);
    }
        
    
    return answer;
}