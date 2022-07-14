#include <string>
#include <vector>
#include <set>
#include <iostream>

#define MAX 10000000001

using ll = long long;
using namespace std;



vector<string> solution(vector<vector<int>> lines) {
    vector<string> answer;
    
    vector<pair<ll,ll>> meet;
    
    ll y_max,y_min,x_max,x_min;
    y_max = x_max = -MAX;
    y_min = x_min = MAX; 
    for(int i=0;i<lines.size();i++){
        for(int j=i+1;j<lines.size();j++){
            ll mo = (ll)lines[i][0]*lines[j][1] - (ll)lines[i][1]*lines[j][0];
            if(mo == 0)
                continue;
            ll x_ja = (ll)lines[i][1]*lines[j][2] - (ll)lines[i][2]*lines[j][1];
            ll y_ja = (ll)lines[i][2]*lines[j][0] - (ll)lines[i][0]*lines[j][2];
            
            if(x_ja%mo == 0 && y_ja%mo == 0){
                x_ja /=mo;
                y_ja /= mo;
                y_max = max(y_max, y_ja);
                x_max = max(x_max, x_ja);
                y_min = min(y_min, y_ja);
                x_min = min(x_min, x_ja);
                meet.push_back(make_pair(y_ja, x_ja));
            }
        }
    }
    ll y_size = y_max - y_min + 1;
    ll x_size = x_max - x_min + 1;

    answer.resize(y_size, string(x_size, '.'));
    
    for(int i=0;i<meet.size();i++){
        answer[y_max - meet[i].first][meet[i].second - x_min] = '*';
    }
    
    return answer;
}