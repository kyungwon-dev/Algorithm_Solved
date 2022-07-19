#include <string>
#include <vector>
#include <sstream>
#include <iostream>

struct traffic{
    int start;
    int end;
    traffic(int a, int b){
        start = a; end = b;
    }
};

using namespace std;

int st[] = {-999,0};
int dt[] = {0,999};

int solution(vector<string> lines) {
    vector<traffic> traffics;
    int answer = 0;
    for(auto line : lines){
        stringstream ss(line);
        string tkn;
        int idx=0, end_time, diff;
        string time[3];
        while(getline(ss, tkn, ' ')){
            if(idx == 1){
                stringstream ss2(tkn);
                int i=0;
                string rs;
                while(getline(ss2, rs, ':')){
                    time[i] = rs;
                    i++;
                }
                end_time = stoi(time[0]) * 60 * 60 * 1000 + stoi(time[1]) * 1000 * 60 + stod(time[2]) * 1000;
            }
            if(idx == 2){
                tkn = tkn.substr(0,tkn.size()-1);
                diff = stod(tkn) * 1000;
            }
            idx++;
        }
        traffics.push_back(traffic(end_time-diff+1, end_time));
    }
    for(auto t : traffics){
        int base = t.start;
        for(int i=0;i<2;i++){
            int cnt = traffics.size();
            int base_st = base + st[i];
            int base_dt = base + dt[i];
            for(auto tt : traffics){
                if(tt.end < base_st || tt.start > base_dt){
                    cnt--;
                }
            }
            answer = max(answer, cnt);
            
        }
    }
    
    for(auto t : traffics){
        int base = t.end;
        for(int i=0;i<2;i++){            
            int cnt = traffics.size();
            int base_st = base + st[i];
            int base_dt = base + dt[i];
            for(auto tt : traffics){
                if(tt.end < base_st || tt.start > base_dt){
                    cnt--;
                }
            }
            answer = max(answer, cnt);
        }
        
    }
    
//     for(int i=0;i<traffics.size();i++){
//         int cnt=traffics.size();
//         for(int j=0;j<traffics.size();j++){
//             if(traffics[i].end > traffics[j].start ||
//                traffics[i].end-1000 > traffics[j].end)
//                 cnt--;
//         }
//         answer = max(cnt, answer);
//     }
    
    return answer;
}