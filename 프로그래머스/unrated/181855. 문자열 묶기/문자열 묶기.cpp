#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    int nums[100000] = {0}; // 길이 저장 배열
    for(string str : strArr){
        nums[str.size()]++;
    }
    
    return *max_element(begin(nums), end(nums));
}