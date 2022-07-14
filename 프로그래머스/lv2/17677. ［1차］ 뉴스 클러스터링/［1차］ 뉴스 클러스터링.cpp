#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> make_set(string s){
    vector<string> rs;
    string tmp;
    for(int i=0;i<s.size();i++){
        if(islower(s[i]))
           s[i] = toupper(s[i]);
        if('A' > s[i] || s[i] > 'Z'){
            tmp.clear();
        }
        else
            tmp.push_back(s[i]);
        if(tmp.size()==2){
            rs.push_back(tmp);
            tmp = tmp[1];
            // tmp.clear();
        }
    }
    return rs;
}

int solution(string str1, string str2) {
    int un=0, inter=0;
    map<string,pair<int,int>> jkd;
    vector<string> str_set = make_set(str1);
    for(auto str : str_set){
        if(jkd.find(str) == jkd.end()){
            jkd[str]= make_pair(1,0);
        }
        else{
            jkd[str].first++;
        }
    }
    
    str_set = make_set(str2);
    for(auto str : str_set){
        if(jkd.find(str) == jkd.end()){
            jkd[str] = make_pair(0,1);
        }
        else{
            jkd[str].second++;
        }
    }
    
    for(const auto& [k, v] : jkd){
        un += max(v.first,v.second);
        inter += min(v.first,v.second);
    }
    
    if(jkd.size()==0)
        return 65536;

    return inter * 65536 / un;
}