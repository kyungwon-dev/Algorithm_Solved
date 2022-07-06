#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<vector<int>> sc(1001, vector<int> (1001, 0));
    queue<pair<int,int>> q;
    q.push({0,1}); //clip, screen
    sc[0][1] = 1;
    while(!q.empty()){
        int c = q.front().first;
        int s = q.front().second;
        q.pop();
        pair<int,int> decision[3];
        decision[0] = {c,s-1};
        decision[1] = {s,s};
        decision[2] = {c,s+c};
        for(int i=0;i<3;i++){
            if(decision[i].second <= 0 || decision[i].second > 1001)
                continue;
            if(decision[i].first > 1000)
                continue;
            if(sc[decision[i].first][decision[i].second] == 0){
                sc[decision[i].first][decision[i].second] = sc[c][s]+1;
                q.push({decision[i].first, decision[i].second});

            }
        }
    }
    int mn = INT32_MAX;
    for(int i=0;i<1001;i++){
        if(sc[i][n] != 0)
            mn = min(mn, sc[i][n]);
    }
    cout << mn-1 << "\n";
    return 0;
}
