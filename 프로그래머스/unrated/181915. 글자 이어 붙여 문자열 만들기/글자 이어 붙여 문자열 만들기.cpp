#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    for(auto index : index_list){
        answer.push_back(my_string[index]);
    }
    return answer;
}