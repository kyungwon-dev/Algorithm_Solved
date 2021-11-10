#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> s_numbers;
    string tmp = "";
    for(char c:s){
        if(c==' '){
            s_numbers.push_back(stoi(tmp));
            tmp.clear();
        }
        else
            tmp.push_back(c);   
    }
    s_numbers.push_back(stoi(tmp));
    return to_string(*min_element(s_numbers.begin(),s_numbers.end())) + " " + to_string(*max_element(s_numbers.begin(),s_numbers.end()));
}