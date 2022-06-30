#include <string>
#include <vector>

using namespace std;
int answer = INT32_MAX;
void calc(string name, vector<bool> isMove, int idx, int remain, int sum){
    if(remain == name.size()){
        answer = min(answer, sum);
        return;
    }
    // 현재 위치 변환
    if(isMove[idx] == false){
        sum = sum + min(name[idx] - 'A', 'Z' - name[idx] + 1);
        remain++;
    }
    // 오른쪽
    int next = idx+1, move=1;
    while(true){
        if(next==name.size())
            next=0;
        if(isMove[next] == false)
            break;
        next++;move++;
        
    }
    if(next == idx) move=0;
    isMove[idx] = true;
    calc(name,isMove,next,remain,sum + move);
    isMove[idx] = false;
    
    // return;
    // 왼쪽
    next = idx-1;move=1;
    while(true){
        if(next==-1)
            next=name.size()-1;
        if(isMove[next] == false)
            break;
        next--;move++;

    }
    if(next == idx) move=0;
    isMove[idx] = true;
    calc(name,isMove,next,remain,sum + move);
    isMove[idx] = false;
}

int solution(string name) {
    int remain=0;
    vector<bool> isMove(name.size(),false);
    for(int i=0;i<name.size();i++){
        if(name[i] == 'A'){
            isMove[i] = true;
            remain++;
        }
    }
    calc(name, isMove, 0, remain, 0);
    return answer;
}