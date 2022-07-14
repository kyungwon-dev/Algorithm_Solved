#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer=0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i : scoville){
        q.push(i);
    }
    while(!q.empty()){
        
        int min_fir = q.top();
        q.pop();
        if(min_fir >= K)
            return answer;
        if(q.empty())
            return -1;
        int min_sec = q.top();
        q.pop();
        q.push(min_fir + 2*min_sec);
        answer++;
        
    }
    
    
    
    return -1;
}