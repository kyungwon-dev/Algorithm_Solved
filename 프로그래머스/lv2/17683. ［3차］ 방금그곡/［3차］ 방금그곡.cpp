#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <regex>
using namespace std;

int trns_time(string sts){
    vector<string> rs;
    string tmp;
    stringstream ss(sts);
    while(getline(ss,tmp,':')){
        rs.push_back(tmp);
    }
    return stoi(rs[0]) * 60 + stoi(rs[1]);
}

string cvrt(string str){
    string cv[5] = {"C#","D#","F#","G#","A#"};
    string ch[5] = {"H","I","J","K","L"};
    for(int i=0;i<5;i++){
        regex re(cv[i]);
        str = regex_replace(str,re,ch[i]);
    }
    return str;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    map<string, string> musicinfo;
    vector<string> lst;
    for(string str : musicinfos){
        vector<string> rs;
        string token;
        stringstream ss(str);
        while(getline(ss,token,',')){
            rs.push_back(token);
        }
        int time = trns_time(rs[1]) - trns_time(rs[0]);
        rs[3] = cvrt(rs[3]);
        string tmp = rs[3];
        int idx= rs[3].length();
        
        
        if(idx > time)
            tmp = tmp.substr(0, time - (idx - rs[3].length()));
        else{
            while(true){
                if(tmp.length() >= (time - rs[3].length()))
                    break;
                tmp += rs[3];
            }

        }
        tmp += rs[3].substr(0,time - tmp.length());
        musicinfo[rs[2]] = tmp;
        lst.push_back(rs[2]);
        
    }
    int mx = INT32_MIN;
    m = cvrt(m);
    for(int i=0;i<lst.size();i++){
        size_t found = musicinfo[lst[i]].find(m);
        if(found!=string::npos){
            if(found + m.length() < musicinfo[lst[i]].length()){
                if(musicinfo[lst[i]][found+m.length()] == '#')
                    continue;
            }
            int len = musicinfo[lst[i]].length();
            string ans = lst[i];
            if(mx < len ){
                mx = len;
                answer = ans;
            }
        }
    }
    if(mx == INT32_MIN)
        answer = "(None)";
    
    
    return answer;
}