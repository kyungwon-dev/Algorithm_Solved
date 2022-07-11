#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    string answer = to_string(n);
    sort(answer.begin(),answer.end(),greater<>());
    return stol(answer);
}