#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <cmath>
using namespace std;

string binaryTransform(string s){
    int num = s.length();
    string rs = "";
    while(num!=0){
        char c = '0' + num%2;
        rs = c + rs;
        num /=2;
    }
    return rs;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    bool isRemove = false;
    regex re("0+");
    while(s.length()!=1){
        int prev_len = s.length();
        s = regex_replace(s,re,"");
        answer[1] = answer[1] + (prev_len - s.length());
        s = binaryTransform(s);
        answer[0]++;
    }
    
    return answer;
}