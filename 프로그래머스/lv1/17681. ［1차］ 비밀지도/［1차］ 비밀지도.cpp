#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0;i<arr1.size();i++){
        bitset<16> bit1(arr1[i]);
        bitset<16> bit2(arr2[i]);
        bit1 = (bit1 | bit2);
        answer.push_back(bit1.to_string(' ', '#'));
        answer[i] = answer[i].substr(answer[i].length()-n,answer[i].length());
    }
        
    
    
    return answer;
}