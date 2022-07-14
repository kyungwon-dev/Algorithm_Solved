#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
vector<vector<int> > cands;

int tot_score(vector<int> &sc, vector<int> &info){
	pair<int, int> tot;
    for(int i=0;i<sc.size();i++){
        if(info[i] < sc[i])
            tot.second += (10-i);
    	else if(info[i] >= sc[i] && info[i] > 0)
            tot.first += (10-i);
    }
	return tot.second - tot.first;
}

void calc_score(vector<int> &answer, vector<int> info, int n, vector<int> &cand, int &diff, int cnt, int idx){
    if(cnt > n )
        return;
    if(cnt == n){
        int sub_diff = tot_score(cand, info);
        if(sub_diff > diff){            
        	diff = sub_diff;
            cands.clear();
            answer.clear();
            answer.assign(cand.begin(),cand.end());
        }
        else{
            if(sub_diff == 0)
                return;
            else if(sub_diff == diff)               
                cands.push_back(cand);
        }
    	return;
    }
    if(idx >= info.size())
        return;
    else{
        cand[idx] = info[idx]+1;
        calc_score(answer, info, n, cand, diff, cnt + info[idx]+1, idx+1);
        if(idx == info.size()-1){
            cand[idx] = n-cnt;
            calc_score(answer, info, n, cand, diff, cnt + cand[idx], idx+1);
        }
        cand[idx] = 0;
        calc_score(answer, info, n, cand, diff, cnt , idx+1);
    }
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int diff = 0;
    vector<int> cand(info.size(), 0);
	calc_score(answer, info, n, cand, diff, 0, 0);
    if(answer.empty() || diff==0){
        answer.clear();
		answer.push_back(-1);
    }
    else{
        if(cands.empty())
			return answer;
        for(int i=0;i<cands.size();i++){
            for(int j=cands[i].size()-1;j>=0;j--){
                if(answer[j] < cands[i][j]){
                    answer.clear();
                    answer.assign(cands[i].begin(),cands[i].end());
                    break;
                }
                else if(answer[j] > cands[i][j])
                    break;
            }
        }
    }
        
    
    return answer;
}