#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    n = n-1;       
        
    for(answer=2;answer<=n;answer++){
        if(n%answer == 0)
            return answer;
    }
    
    return n-1;
}