#include <string>
#include <vector>

using namespace std;

bool isPosition(int n, vector<int> &queens, int level, int idx){
    if(queens[idx] != 0)
        return false;
    for(int i=0;i<level;i++){
        
        if( (idx - i) >= 0 ){
            if(queens[idx-i] == (level - i) )
                return false;
        }
        if( (idx + i) < n){
            if(queens[idx+i] == (level - i) )
                return false;
        }
    }
    return true;
}

void calc(int &answer, int n, vector<int> &queens, int level){
    if(level > n) 
        answer++;
    else{
        for(int i=0;i<n;i++){
            if(isPosition(n, queens, level, i)){
                queens[i] = level;
                calc(answer, n, queens, level+1);
                queens[i] = 0;
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> queens(n,0);
    calc(answer, n, queens, 1);
    
    return answer;
}