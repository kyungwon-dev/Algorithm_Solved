#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <regex>

using namespace std;

void init(map<string, string> &str2int){
    str2int.insert({"zero","0"});
    str2int.insert({"one","1"});
    str2int.insert({"two","2"});
    str2int.insert({"three","3"});
    str2int.insert({"four","4"});
    str2int.insert({"five","5"});
    str2int.insert({"six","6"});
    str2int.insert({"seven","7"});
    str2int.insert({"eight","8"});
    str2int.insert({"nine","9"});
}
int solution(string s) {
    string answer = "";
    map<string, string> str2int;
    init(str2int);
    for(auto k: str2int){
        regex re(k.first);
        s = regex_replace(s,re,k.second);   
    }
    //cout << stoi(s) << "\n";
    
    return stoi(s);
}