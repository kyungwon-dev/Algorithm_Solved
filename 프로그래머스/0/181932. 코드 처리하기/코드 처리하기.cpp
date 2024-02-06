#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    int mode = 0;
    for(int i=0;i<code.size();i++){
        if(mode == 0){
            if(code[i] == '1'){
                mode = 1;
                continue;
            }
            if(i%2 == 0) ret = ret + code[i];
            
        } else{
            if(code[i] == '1'){
                mode = 0;
                continue;
            }
            if(i%2 == 1) ret = ret + code[i];
        }
    }
    if(ret.size() == 0) ret = "EMPTY";
    return ret;
}