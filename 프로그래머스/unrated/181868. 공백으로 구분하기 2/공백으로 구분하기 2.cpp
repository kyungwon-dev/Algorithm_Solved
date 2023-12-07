#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    bool isSpace = true;
    string tmp = "";
    for(int i=0;i<my_string.size();i++){
        if(my_string[i] == ' '){
            if(tmp.size() == 0)
                continue;
            else{
                answer.push_back(tmp);
                tmp = "";
            }
        } else{
            tmp.push_back(my_string[i]);
        }
        
    }
    if(tmp.size()!= 0){
        answer.push_back(tmp);
    }
    return answer;
}