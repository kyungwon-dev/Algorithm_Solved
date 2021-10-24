#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> split_s;
    string splits_result = "";
    for(char c : s){
        
        if(c == ' '){
            split_s.push_back(splits_result);
            split_s.push_back(" ");
            splits_result = "";
        }
        else{
            if(splits_result.length()==0){
                if(c <= '9')
                    splits_result.push_back(c);    
                else
                    splits_result.push_back(toupper(c));    
            }
            else{
                if(c <= '9')
                    splits_result.push_back(c);    
                else
                    splits_result.push_back(tolower(c));    
                
            }
        }
    }
    for(string str : split_s)
        answer += str;
    answer += splits_result;
    return answer;
}