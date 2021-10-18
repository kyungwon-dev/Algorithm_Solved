#include <string>
#include <regex>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int scores[3][3];
    regex re("([0-9]+)([SDT])([*#]?)([0-9]+)([SDT])([*#]?)([0-9]+)([SDT])([*#]?)");
    smatch match;
    if(regex_match(dartResult,match,re)){
        for(int i=1;i<match.size();i++){
            int rs = 0;
            if(match[i].str() == "")
                rs = 1;
            else if(match[i].str() == "S")
                rs = 1;
            else if(match[i].str() == "D")
                rs = 2;
            else if(match[i].str() == "T")
                rs = 3;
            else if(match[i].str() == "*"){
                rs = 2;
                if(((i-1)/3) > 0)
                    scores[(i-1-3)/3][(i-1)%3] *= (2);
            }
            else if(match[i].str() == "#")
                rs = -1;
            else
                rs = stoi(match[i].str());
            scores[(i-1)/3][(i-1)%3] = rs;
        }
    }
    for(int i=0;i<3;i++){
        answer +=  (int) pow(scores[i][0],scores[i][1]) * scores[i][2];
    }
        
    return answer;
}