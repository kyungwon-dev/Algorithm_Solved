#include <string>
#include <vector>
#include <map>
#include <regex>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> nickname;
    vector<pair<string,string>> messages ;
    regex re("(\\w+)\\ ([a-zA-z0-9]{1,10})(\\ )*([a-zA-Z0-9]{1,10})*");
    //regex rex("(\\w+)\\ ([^a-z][A-Za-z0-9 ]{1,10})([^A-Z][a-zA-Z0-9 ]{1,10})*");
    smatch match;
    for(string str : record){
        if (regex_match(str, match, re)){
            if(match[1] != "Leave"){
                if(nickname.find(match[2])!=nickname.end())
                    nickname[match[2]];    
                nickname[match[2]] = match[4];
            }
            if(match[1] != "Change"){
                messages.push_back({match[1],match[2]});    
            }    
        }

    }
    for(pair<string,string> message : messages){
        string user = nickname[message.second];
        string msg = (message.first == "Enter" ? "님이 들어왔습니다." : "님이 나갔습니다.");
        answer.push_back(user+msg);
        
    }
    return answer;
}