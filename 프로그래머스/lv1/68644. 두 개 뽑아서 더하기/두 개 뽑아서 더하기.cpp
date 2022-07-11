#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void two_sum(vector<int> number,int pick_sum, int idx, int pick_cnt, vector<int> &answer){
    if(pick_cnt==2){
        answer.push_back(pick_sum);
        return;
    }
    if(idx==number.size())
        return;
    two_sum(number,pick_sum+number[idx],idx+1,pick_cnt+1,answer);
    two_sum(number,pick_sum,idx+1,pick_cnt,answer);
    
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    two_sum(numbers, 0, 0, 0, answer);
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    return answer;
}