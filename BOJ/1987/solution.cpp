#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int dfs(vector<vector<char> > &map, vector<bool> &isCheck, int y, int x, int subsum){
    int dy[4] = {0,0,1,-1};
    int dx[4] = {-1,1,0,0};
    int answer = subsum;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(yy < 0 || yy >= map.size() || xx < 0 || xx >= map[0].size())
            continue;
        if(isCheck[map[yy][xx] - 'A'])
            continue;
        isCheck[map[yy][xx] - 'A'] = true;
        answer = max(answer, dfs(map, isCheck, yy,xx, subsum+1));    
        isCheck[map[yy][xx] - 'A'] = false;
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c, answer=INT32_MIN;
    cin >> r >> c;
    vector<vector<char> > map(r, vector<char>(c));
    vector<bool> isCheck(26);
    for(auto &m : map){
        for(auto &c : m){
            cin >> c;
        }
    }
    isCheck[map[0][0] - 'A'] = true;
    cout << dfs(map, isCheck, 0 ,0, 1) << "\n";    

    return 0;
}