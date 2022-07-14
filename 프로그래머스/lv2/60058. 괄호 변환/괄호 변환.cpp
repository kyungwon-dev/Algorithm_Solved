#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool correct_brace(string u){
    stack<char> s;
    for(auto c : u){
        if(c=='(')
            s.push(c);
        else{
            if(s.empty())
                return false;
            s.pop();
        }
    }
    if(s.empty())
        return true;
    return false;
}

int balanced_brace(string w){
    int idx=0, cnt=0;
    while(true){
        if(w[idx++] == '(')
            cnt++;
        else
            cnt--;
        if(cnt==0)
            break;
    }
    return idx;
}


string make_correct(string p){
    // 1.
    if(p.length()==0)
        return "";
    // 2.
    int idx = balanced_brace(p);
    string u = p.substr(0,idx);
    string v = p.substr(idx);
    // 3.
    if(correct_brace(u))
        return u + make_correct(v); // 3-1.
    // 4-1. ~ 4-3.
    string trms = "(" + make_correct(v) + ")";
    
    // 4-4.
    u.erase(0,1);
    u.erase(u.length()-1,u.length());
    
    // 4-5.
    for(int i=0;i<u.length();i++){
        if(u[i] == '(')
            u[i] = ')';
        else
            u[i] = '(';
    }
    
    return trms + u;
}


string solution(string p) {
    if(correct_brace(p))
        return p;
    return make_correct(p);;
}