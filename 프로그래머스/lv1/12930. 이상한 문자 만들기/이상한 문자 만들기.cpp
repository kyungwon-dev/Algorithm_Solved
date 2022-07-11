#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    char tok = ' ';
    int idx = 0;
    string tmp = "";
    for(char &c : s){
        if(c == tok){
            idx = 0;
        }
        else{
            if(idx%2==0)
                c = toupper(c);
            else
                c = tolower(c);
            idx++;
        }
    }
    return s;
}