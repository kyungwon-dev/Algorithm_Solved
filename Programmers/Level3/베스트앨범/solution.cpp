#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

struct music{
    int idx;
    int plays;
};

using namespace std;
bool compare(struct music &a,struct music &b){
    if(a.plays != b.plays)
        return a.plays > b.plays;
    return a.idx < b.idx;
}

bool compare_sum(pair<string,int> &a, pair<string,int> &b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string,vector<struct music>> publish;
    int length = genres.size();
    vector<pair<string,int>> playNums;
    vector<int> answer;
    
    for(int i=0;i<length;i++)
    {
        struct music tmp;
        publish[genres[i]];
        tmp.idx = i;
        tmp.plays = plays[i];
        publish[genres[i]].push_back(tmp);
    }
    for(auto it = publish.begin();it!=publish.end();it++)
    {
        int sum=0;
        for(int i=0;i<it->second.size();i++)
            sum += it->second[i].plays;
    
        playNums.push_back({it->first,sum});
        sort(it->second.begin(),it->second.end(),compare);
    }
    sort(playNums.begin(),playNums.end(),compare_sum);
    for(auto it = playNums.begin();it!=playNums.end();it++)
    {
        answer.push_back(publish[it->first][0].idx);
        if(publish[it->first].size() >=2)
            answer.push_back(publish[it->first][1].idx);
    }
    
    return answer;
}