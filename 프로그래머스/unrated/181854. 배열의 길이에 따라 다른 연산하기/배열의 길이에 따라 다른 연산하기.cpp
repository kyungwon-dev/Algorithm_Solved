#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int i = 1;
    if(arr.size() %2 == 1){
        i = 0;
    }
    for(;i<arr.size();i+=2){
        arr[i] += n;        
    }
    return arr;
}