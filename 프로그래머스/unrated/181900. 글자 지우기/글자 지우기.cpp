#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    vector<bool> except(my_string.size(), true);
    
    for(int i=0;i<indices.size();i++){
        except[indices[i]]= false;
    }
    
    for(int i=0;i<except.size();i++){
        if(except[i]) {
            answer.push_back(my_string[i]);
        }
    }
    return answer;
}