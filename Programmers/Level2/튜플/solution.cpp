#include <string>
#include <vector>
#include <queue>
#include <set>
#include <sstream>

using namespace std;

struct number{
    string str;
    int comma_len;
    
    number(string s, int n){
        str = s;
        comma_len = n;
    }
    bool operator< (const number &a)const {
        return comma_len > a.comma_len;
    }
};


vector<int> solution(string s) {
    vector<int> answer;
    priority_queue<number> number_set;
    for(int i=1;i<s.length();i++){
        if(s[i] == '{'){
            string rs;
            int comma_len=0;
            i++;
            while(s[i]!='}'){
                rs.push_back(s[i]);
                i++;
                if(s[i] == ',') comma_len++;
            }
            number_set.push(number(rs,comma_len));
        }
    }
    set<int> rs;
    while(!number_set.empty()){
        string tkn;
        istringstream ss(number_set.top().str);
        while(getline(ss, tkn, ',')){
            int a = stoi(tkn), s = rs.size();
            rs.insert(a);
            if(s!=rs.size())
                answer.push_back(a);
        }
        number_set.pop();
    }
    
    return answer;
}