#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool isMakeCorrect(string s){
    stack<char> st;
    
    int s_cnt = 0,m_cnt = 0,l_cnt = 0;
    for(auto c : s){
        if(c== '{' || c== '[' || c== '('){
            st.push(c);
        }
        else{
            if(s.size()==0)
                return false;
            if(c== '}'){
                if(st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            if(c== ']'){
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            if(c== ')'){
                if(st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
    }
    if(st.size() == 0)
        return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.length();i++){
        rotate(s.begin(),s.begin()+1,s.end());
        if(isMakeCorrect(s))
            answer++;
    }
    return answer;
}