#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int idx = 0;
bool compare(string a, string b){
    if(a[idx] == b[idx])
        return a < b;
    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(),strings.end(),compare);
    
    return strings;
}