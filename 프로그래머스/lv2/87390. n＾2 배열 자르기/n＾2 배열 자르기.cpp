#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while(left != (right+1)){
        long long i = left / n;
        long long j = left % n;
        answer.push_back(max(i,j)+1);
        left++;
    }
    return answer;
}