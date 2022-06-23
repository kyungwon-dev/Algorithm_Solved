#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool isNumeric(char c){
    if('0' <= c && c <= '9')
        return true;
    return false;
}

long long solution(string expression) {
    long long answer = 0;
    string op;
    char ch[3] = {'+','-','*'};
    // 연산자 종류 정의
    for(int i=0;i<3;i++){
        if(expression.find(ch[i]) != string::npos)
            op.push_back(ch[i]);
    }
    sort(op.begin(),op.end()); // 순열을 위해 정렬
    
    string origin = expression + "";
    do{
        expression = origin;
        string tmp = "";
        for(int i=0;i<op.length();i++){
            string number;
            for(int j=0;j<expression.length();j++){
                char ch = expression[j];
                if(isNumeric(expression[j]))
                    number.push_back(expression[j]);
                else{
                    if(op[i] == ch){
                        string number2;
                        int k=j+1;
                        for(;k<expression.length();k++){
                            if(number2.length()==0 && expression[k] == '-'){
                                number2.push_back(expression[k]);
                                continue;
                            }
                            if('0' <= expression[k] && expression[k] <= '9')
                                number2.push_back(expression[k]);
                            else
                                break;
                        }
                        j=k-1;
                        if(ch == '*')
                            number = to_string(stol(number) * stol(number2));
                        if(ch == '+')
                            number = to_string(stol(number) + stol(number2));
                        if(ch == '-')
                            number = to_string(stol(number) - stol(number2));
                    }   
                    else{
                        if(number.length()==0)
                            number.push_back(ch);
                        else{
                            tmp += number + expression[j];
                            number = "";
                        }
                            
                    }
                }
            }
            tmp += number;
            expression = tmp;
            tmp = "";
        }
        if(answer < abs(stol(expression)))
            answer = abs(stol(expression));
    }while(next_permutation(op.begin(),op.end()));
    
    return answer;
}