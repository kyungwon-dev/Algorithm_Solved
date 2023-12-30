#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int i=1;
    for(;i<1024;i*=2){
        if(arr.size() > i) continue;
        else if(arr.size() == i) return arr;
        else break;
    }
    for(int j=arr.size();j<i;j++)
        arr.push_back(0);
    return arr;
}