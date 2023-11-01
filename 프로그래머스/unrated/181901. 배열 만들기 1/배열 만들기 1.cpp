#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer(n/k);
    for(int i=k;i<=n;i+=k) answer[i/k-1] = i;
    return answer;
}