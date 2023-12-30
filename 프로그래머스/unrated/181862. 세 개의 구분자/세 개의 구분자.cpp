#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    for(auto &str : myStr){
        if(str == 'a' || str == 'b' || str == 'c'){
            str = ' ';
        }
    }
    stringstream ss(myStr);
    string tkn = "";
    while(getline(ss, tkn, ' ')){
        if(tkn == "") continue;
        answer.push_back(tkn);
    }
    if(answer.size() == 0) answer.push_back("EMPTY");
    return answer;
}