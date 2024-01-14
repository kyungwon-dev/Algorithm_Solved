#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    for(int i=0;i<queries.size();i++){
        string front = my_string.substr(0, queries[i][0]);
        string mid = my_string.substr(queries[i][0], queries[i][1] - queries[i][0] + 1);
        string back = my_string.substr(queries[i][1]+1, my_string.size() - queries[i][1]);
        reverse(mid.begin(),mid.end());
        my_string = front + mid + back;
    }
    return my_string;
}