#include <string>
#include <vector>
#include <set>

using namespace std;

vector<vector<string>> rs;
vector<string> answers;

int cvrt_vec_to_set(vector<string> v){
    set<string> s(v.begin(),v.end());
    return s.size();
}

void calc(int len, vector<int> indexes, int p){
    if(len == indexes.size()){
        vector<string> candidates;
        for(int i=0;i<rs.size();i++){
            string tmp = "";
            for(auto idx : indexes)
                tmp = tmp + rs[i][idx];
            candidates.push_back(tmp);
        }
        if(cvrt_vec_to_set(candidates) == candidates.size()){
            string candidate = "";
            for(auto idx : indexes)
                candidate += to_string(idx);
            answers.push_back(candidate);    
        }
        
        
        return;
    }
    for(int i=p;i<rs[0].size();i++){
        indexes.push_back(i);
        calc(len, indexes, i+1);
        indexes.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    rs = relation;
    
    // 유일성을 만족하는 조건 탐색.
    for(int i=1;i<=relation.size();i++){
        vector<int> indexes;
        calc(i,indexes,0);
    }
    
    // 유일성을 만족하는 후보 중 최소성을 만족하는 값만 탐색
    for(int i=0;i<answers.size();i++){
        for(int j=i+1;j<answers.size();j++){
            if(answers[j].find(answers[i]+"") != string::npos){
                answers.erase(answers.begin()+j);
                j--;
            }
            else{
                if(answers[i].length()==1)
                    continue;
                int isSame = 0;
                for(int k=0;k<answers[i].length();k++){
                    for(int l=0;l<answers[j].length();l++){
                        if(answers[i][k] == answers[j][l])
                            isSame++;
                    }
                }
                if(isSame == answers[i].length()){
                    answers.erase(answers.begin()+j);
                    j--;
                }
            }
        }
    }
    for(int i=0;i<answers.size();i++){
        for(int j=i+1;j<answers.size();j++){
            if(answers[j].find(answers[i]+"") != string::npos){
                answers.erase(answers.begin()+j);
                j--;
            }
        }
    }
    return answers.size();
}