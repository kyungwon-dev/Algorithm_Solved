#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mod_three(int n){
    if(n%3==0)
        return 4;
    if(n%3==2)
        return 2;
    return 1;
}


string solution(int n) {
    string answer = "";
    while(n>0){
        int mod_result = mod_three(n);
        answer = to_string(mod_result) + answer;
        n -= (n%3 == 0? 3 : n%3);
        n /=3;
        
    }
    return answer;
}