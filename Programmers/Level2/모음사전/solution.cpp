#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string word) {
    int answer = 1;
    char c[5] = {'A','E','I','O','U'};
    string str = "A";
    while(true){
        if(str == word) break;
        else{
            if(str.length()<5){
                str.push_back('A');
            
            }
            else{
                while(str[str.length()-1] == 'U')
                    str.pop_back();
                if(str.length()==0)
                    break;
                for(int i=0;i<4;i++){
                    if(str[str.length()-1] == c[i]){
                        str[str.length()-1] = c[i+1];
                        break;
                    }
                }
            }
        }
        answer++;
            
    }
    return answer;
}