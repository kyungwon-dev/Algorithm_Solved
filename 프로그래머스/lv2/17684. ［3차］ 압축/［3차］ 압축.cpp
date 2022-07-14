#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> LZW;
    map<string, int>::iterator it;
    int idx;
    for(idx=1;idx<27;idx++){
        string str;
        str.push_back( (char) ('A' + idx -1));
        LZW[str] = idx;
    }
    string tmp;
    tmp.push_back(msg[0]);
    for(int i=1;i<msg.size();i++){
        //tmp.push_back(msg[i]);
        it = LZW.find(tmp + msg[i]);
        if(it != LZW.end()){
            tmp.push_back(msg[i]);
        }
        else{
            //cout << tmp + msg[i] << "\n";
            answer.push_back(LZW[tmp]);
            LZW[tmp + msg[i]] = idx++;
            tmp.clear();
            tmp.push_back(msg[i]);
        }
        
    }
    answer.push_back(LZW[tmp]);
    
    return answer;
}