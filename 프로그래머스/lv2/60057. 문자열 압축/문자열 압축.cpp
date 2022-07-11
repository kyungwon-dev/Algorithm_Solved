#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    bool noCompress = true;
    if(s.length()<=2)
        return s.length();
    int idx = 1;
    while(idx < (s.length()/2+1)){
        string tmp = "";
        int i=0;
        for(i=0;i<=s.length()-idx;i+=idx){
            string token = s.substr(i,idx);
            if(token == s.substr(i+idx,idx)){
                int count = 1;
                int j = i + idx;
                for(;j<s.length();j+=idx){
                    if(token == s.substr(j,idx))
                        count++;
                    else{
                        break;
                    }
                        
                }
                i = (j-idx);
                tmp = tmp + to_string(count) + token;
            }
            else{
                tmp = tmp + token;
            }    
        }
        //cout << s.length() - i + idx << "\n";
        if( s.length() - i < idx)
            tmp = tmp + s.substr(i);
        
        if(tmp.length() < answer)
            answer = tmp.length();
        idx++;
    }
    
    return answer;
}