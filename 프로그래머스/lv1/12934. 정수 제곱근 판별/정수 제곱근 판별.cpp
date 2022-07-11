#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    if(n==1)
        return 4;
    for(long long i=2;(i*i)<=n;i++){
        if(n== (i*i))
            return (i+1)*(i+1);
    }
        
    return -1;
}