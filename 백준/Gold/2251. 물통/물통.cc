#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct bottle{
    int bot[3];
    bottle(int a[]){
        bot[0] = a[0];
        bot[1] = a[1];
        bot[2] = a[2];
    }
};

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int st[] = {0,0,1,1,2,2};
int dt[] = {1,2,0,2,0,1};
int rm[] = {2,1,2,0,1,0};

string array_to_string(int a[]){
    return to_string(a[0]) + " " + to_string(a[1]) + " " + to_string(a[2]);
}

int main()
{
    init();
    map<string,bool> isVisit;
    vector<int> answer;
    int maximum_water[3];
    cin >> maximum_water[0] >> maximum_water[1] >> maximum_water[2];
    answer.push_back(maximum_water[2]);
    queue<bottle> q;
    bottle init_value = bottle(maximum_water);
    init_value.bot[0] = init_value.bot[1] = 0;
    q.push(bottle(init_value));
    isVisit[array_to_string(init_value.bot)] = true;
    while(!q.empty()){
        bottle now = q.front();
        q.pop();
        for(int k=0;k<6;k++){
            if(now.bot[st[k]] == 0) continue;
            if(now.bot[dt[k]] == maximum_water[dt[k]]) continue;
            int start = 0;
            int dest = now.bot[st[k]] + now.bot[dt[k]];
            if(dest > maximum_water[dt[k]]){
                start = dest - maximum_water[dt[k]];
                dest = maximum_water[dt[k]];
            }
            int rs[3];
            rs[st[k]] = start;
            rs[rm[k]] = now.bot[rm[k]];
            rs[dt[k]] = dest;
            string key = array_to_string(rs);
            if(isVisit.find(key) != isVisit.end()) continue;
            isVisit[key] = true;
            q.push(bottle(rs));
            if(rs[0] == 0)
                answer.push_back(rs[2]);
        }        
    }
    sort(answer.begin(),answer.end());
    for(auto a : answer) cout << a << " ";
    cout << "\n";
    


 	return 0;
}