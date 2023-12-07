#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    while(idx < arr.size()){
        if(arr[idx] == 1) 
            return idx;
        idx++;
    }
    return -1;
}