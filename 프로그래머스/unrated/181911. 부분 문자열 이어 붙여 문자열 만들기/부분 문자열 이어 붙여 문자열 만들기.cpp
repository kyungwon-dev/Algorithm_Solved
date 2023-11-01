#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    int idx =0;
    for(auto part : parts){
        pair<int,int> start_end(part[0], part[1]);
        answer += my_strings[idx++].substr(start_end.first, start_end.second - start_end.first + 1);
    }
    return answer;
}