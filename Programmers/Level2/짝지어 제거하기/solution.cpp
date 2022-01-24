#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;

    if(s.length()%2 != 0)
        return answer;
    if(s.length()<2)
        return answer;
    vector<char> stacked;
    for(char c : s){
        if(stacked.empty())
            stacked.push_back(c);
        else{
            if(stacked[stacked.size()-1] == c)
                stacked.pop_back();
            else
                stacked.push_back(c);
        }
    }
    if(stacked.empty())
		return answer+1;
    
    return answer;
}