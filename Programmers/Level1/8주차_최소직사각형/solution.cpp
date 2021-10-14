#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> w;
    vector<int> h;
    for(vector<int> size : sizes){
        int maxIndex = size[0]>size[1] ? 0 : 1;
        w.push_back(size[maxIndex]);
        h.push_back(size[(maxIndex+1)%2]);
    }
    
    return (*max_element(w.begin(),w.end())) * (*max_element(h.begin(),h.end()));
}