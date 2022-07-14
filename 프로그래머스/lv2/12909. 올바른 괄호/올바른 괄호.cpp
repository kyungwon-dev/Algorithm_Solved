#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    
    int isClose = 0;
    if(s[0]==')' || s[s.length()-1]=='(')
        return false;
    for(char c : s){
        if(c=='(')
            isClose++;
        else
            isClose--;
        if(isClose<0)
            return false;
    }        
    if(isClose==0)
        return true;
    return false;
}