#include <string>
#include <vector>

using namespace std;
void aa(int n, int & answer,int current, int sum){
    
    if(sum==n){
        answer+=1;
        return;
    }
    if(current >= n){
        return;
    }
        
    if(sum<n){
        aa(n,answer,current+1,sum+current);
        if(sum==0)
            aa(n,answer,current+1,sum);
    }        
    
}

int solution(int n) {
    int answer = 0;
    aa(n,answer,1,0);
    
    
    return answer+1;
}