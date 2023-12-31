#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    int minIndex = INT32_MAX, maxIndex = INT32_MIN;
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
        if( arr[i]== 2){
            minIndex = min(i, minIndex);
            maxIndex = max(maxIndex, i);
        }
    }
    
    // cout << minIndex << " " << maxIndex << "\n";
    while(minIndex <= maxIndex){
        answer.push_back(arr[minIndex]);
        minIndex++;
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    return answer;
}