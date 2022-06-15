#include <vector>
#include <cmath>

using namespace std;

long long calc(long long n){
    if(n<2)
        return 0;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0){
            long long rs = n/i;
            if(rs >= 10000000)
                continue;
            return rs;
        }
    }
    return 1;
}


vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    while(begin <= end){
        answer.push_back(calc(begin));
        begin++;
    }
    return answer;
}