#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(int i=0;i<myString.size();i++){
        string tmp = myString.substr(i, pat.size());
        if(pat == tmp) answer++;
    }
    return answer;
}