#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    long long tmp = n * m;
    tmp = tmp / answer[0];
    answer.push_back(tmp);
    return answer;
}