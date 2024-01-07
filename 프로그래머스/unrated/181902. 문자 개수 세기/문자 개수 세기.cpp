#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    for(auto c : my_string){
        if('a' <= c && c <= 'z'){
            answer[c-'a'+26]++;
        } else{
            answer[c-'A']++;
        }
    }
    return answer;
}